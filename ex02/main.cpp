/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:27:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/21 03:10:33 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
		std::cerr << RED "Error" RESET << std::endl;
		return 1;
    }

	std::string input;
	for (int i = 1; i < ac; ++i)
	{
		if (i > 1)
			input += " ";
		input += av[i];
	}

	PmergeMe p(input);
	if (!p.ParseInput())
	{
		std::cerr << RED "Error" RESET << std::endl;
		return 1;
	}

	p.BeforePrint();
	p.SortVector();
	p.SortList();
	p.AfterPrint();
	p.TimePrint();
    return 0;
}
