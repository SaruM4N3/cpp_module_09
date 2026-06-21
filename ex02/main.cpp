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
		std::cout << RED "Error: Wrong argument nbr" RESET << std::endl;
		return 1;
    }
	PmergeMe p(av[1]);
	p.ParseInput();
	p.BeforePrint();
    return 0;
}
