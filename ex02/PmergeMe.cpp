/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:41:38 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/21 03:06:50 by zsonie           ###   ########lyon.fr   */
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

void PmergeMe::SortVector()
{
	double start = GetTimestampUs();

	// TODO: Ford-Johnson merge-insert sort sur _vec (std::vector<int>)

	double end = GetTimestampUs();
	_vectorTime = end - start;
}

void PmergeMe::SortList()
{
	double start = GetTimestampUs();

	// TODO: Ford-Johnson merge-insert sort sur _lst (std::list<int>)

	double end = GetTimestampUs();
	_listTime = end - start;
}