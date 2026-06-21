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

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::string before): _before(before)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	(void) copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
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

static void ThirdPrint(int nbrElement, double firstContainerTime)
{
	std::cout << "Time to process a range of  "<< nbrElement << " elements with std::[..] :  "<< firstContainerTime <<"us"<< std::endl;
}

static void FourthPrint(int nbrElement, double secondContainerTime)
{
	std::cout << "Time to process a range of  "<< nbrElement << " elements with std::[..] :  "<< secondContainerTime <<"us"<< std::endl;
}

bool PmergeMe::ParseInput()
{
	std::istringstream iss(_before);
	std::string tokens;
	while (iss >> tokens)
	{
		_lst.push_back(atoi(tokens.c_str()));
		std::cout << tokens << std::endl;
		_nbrElements++;
	}
	std::cout << "nbrElem = " << _nbrElements << std::endl;
	ThirdPrint(_nbrElements, _algoTime);
	FourthPrint(_nbrElements, _algoTime);
	return true;
}