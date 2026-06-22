/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:41:41 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/21 03:10:43 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(std::string before);
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

	void BeforePrint();
	void AfterPrint();
	void TimePrint();
	bool ParseInput();

	void SortVector();
	void SortList();

private:
	std::string _before;
	std::string _after;
	int _nbrElements;
	double _vectorTime;
	double _listTime;
	std::vector<int> _vec;
	std::list<int> _lst;

	std::vector<size_t> MergeInsertVector(std::vector<size_t> idx);
	void MergeInsertList(std::list<int> &chain);
	void BuildAfter();

	static double GetTimestampUs();
};

#endif