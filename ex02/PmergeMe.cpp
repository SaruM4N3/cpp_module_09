/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:41:38 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/22 02:26:13 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _nbrElements(0), _vectorTime(0), _listTime(0)
{
}

PmergeMe::PmergeMe(std::string before): _before(before), _nbrElements(0), _vectorTime(0), _listTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_before = copy._before;
		_after = copy._after;
		_nbrElements = copy._nbrElements;
		_vectorTime = copy._vectorTime;
		_listTime = copy._listTime;
		_vec = copy._vec;
		_lst = copy._lst;
	}
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::BeforePrint()
{
	std::cout << "Before:  "<< _before << std::endl;
}

void PmergeMe::AfterPrint()
{
	std::cout << "After:   "<< _after << std::endl;
}

void PmergeMe::TimePrint()
{
	std::cout << "Time to process a range of " << _nbrElements
		<< " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _nbrElements
		<< " elements with std::list : " << _listTime << " us" << std::endl;
}

double PmergeMe::GetTimestampUs()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}

bool PmergeMe::ParseInput()
{
	std::istringstream iss(_before);
	std::string token;
	std::ostringstream beforeStream;

	while (iss >> token)
	{
		if (token.empty() || token.size() > 10)
			return false;
		for (std::string::size_type i = 0; i < token.size(); ++i)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[i])))
				return false;
		}

		errno = 0;
		char *end = NULL;
		long value = std::strtol(token.c_str(), &end, 10);
		if (*end != '\0' || errno == ERANGE || value > INT_MAX || value < 1)
			return false;

		if (_nbrElements > 0)
			beforeStream << " ";
		beforeStream << value;

		_vec.push_back(static_cast<int>(value));
		_lst.push_back(static_cast<int>(value));
		_nbrElements++;
	}
	if (_nbrElements == 0)
		return false;
	_before = beforeStream.str();
	return true;
}

std::vector<size_t> PmergeMe::MergeInsertVector(std::vector<size_t> idx)
{
	size_t n = idx.size();
	if (n <= 1)
		return idx;

	std::vector<size_t> winners;
	std::vector<size_t> loserIdx;
	std::vector<size_t> loserBoundWinner;

	size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		size_t a = idx[i];
		size_t b = idx[i + 1];
		if (_vec[a] < _vec[b])
			std::swap(a, b);
		winners.push_back(a);
		loserIdx.push_back(b);
		loserBoundWinner.push_back(a);
	}
	bool hasStraggler = (i < n);
	size_t straggler = hasStraggler ? idx[i] : 0;

	std::vector<size_t> mainChain = MergeInsertVector(winners);

	std::vector<size_t> position(_vec.size());
	for (size_t k = 0; k < mainChain.size(); ++k)
		position[mainChain[k]] = k;

	for (size_t k = 0; k < loserIdx.size(); ++k)
	{
		size_t bound = position[loserBoundWinner[k]];
		size_t lo = 0, hi = bound;
		while (lo < hi)
		{
			size_t mid = lo + (hi - lo) / 2;
			if (_vec[mainChain[mid]] < _vec[loserIdx[k]])
				lo = mid + 1;
			else
				hi = mid;
		}
		mainChain.insert(mainChain.begin() + lo, loserIdx[k]);
		for (size_t p = lo; p < mainChain.size(); ++p)
			position[mainChain[p]] = p;
	}

	if (hasStraggler)
	{
		size_t lo = 0, hi = mainChain.size();
		while (lo < hi)
		{
			size_t mid = lo + (hi - lo) / 2;
			if (_vec[mainChain[mid]] < _vec[straggler])
				lo = mid + 1;
			else
				hi = mid;
		}
		mainChain.insert(mainChain.begin() + lo, straggler);
	}

	return mainChain;
}

void PmergeMe::SortVector()
{
	double start = GetTimestampUs();

	std::vector<size_t> idx(_vec.size());
	for (size_t i = 0; i < idx.size(); ++i)
		idx[i] = i;

	std::vector<size_t> sortedIdx = MergeInsertVector(idx);

	std::vector<int> result(sortedIdx.size());
	for (size_t i = 0; i < sortedIdx.size(); ++i)
		result[i] = _vec[sortedIdx[i]];
	_vec = result;

	double end = GetTimestampUs();
	_vectorTime = end - start;
	BuildAfter();
}

void PmergeMe::MergeInsertList(std::list<int> &chain)
{
	if (chain.size() <= 1)
		return;

	std::list<int> winners;
	std::vector<int> loserValue;
	std::vector<std::list<int>::iterator> loserBound;

	std::list<int>::iterator it = chain.begin();
	while (it != chain.end())
	{
		std::list<int>::iterator a = it++;
		if (it == chain.end())
			break;
		std::list<int>::iterator b = it++;
		if (*a < *b)
			std::swap(*a, *b);
		winners.splice(winners.end(), chain, a);
		loserValue.push_back(*b);
		loserBound.push_back(a);
		chain.erase(b);
	}
	bool hasStraggler = !chain.empty();
	int straggler = hasStraggler ? chain.front() : 0;

	MergeInsertList(winners);

	chain.clear();
	chain.splice(chain.begin(), winners);

	for (size_t k = 0; k < loserValue.size(); ++k)
	{
		std::list<int>::iterator bound = loserBound[k];
		std::list<int>::iterator pos = chain.begin();
		while (pos != bound && *pos < loserValue[k])
			++pos;
		chain.insert(pos, loserValue[k]);
	}

	if (hasStraggler)
	{
		std::list<int>::iterator pos = chain.begin();
		while (pos != chain.end() && *pos < straggler)
			++pos;
		chain.insert(pos, straggler);
	}
}

void PmergeMe::SortList()
{
	double start = GetTimestampUs();

	MergeInsertList(_lst);

	double end = GetTimestampUs();
	_listTime = end - start;
}

void PmergeMe::BuildAfter()
{
	std::ostringstream afterStream;
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		if (i > 0)
			afterStream << " ";
		afterStream << _vec[i];
	}
	_after = afterStream.str();
}