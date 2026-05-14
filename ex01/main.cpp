/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:27:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/05/14 22:39:50 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
		std::cout << RED "Error: could not open file" RESET << std::endl;
		return 1;
    }

    return 0;
}
