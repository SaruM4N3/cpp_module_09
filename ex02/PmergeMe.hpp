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
	bool ParseInput();

private:
	std::string _before;
	std::string _after;
	int _nbrElements;
	double _algoTime;
	std::vector<int>_vec; 
	std::list<int> _lst; 
};

#endif