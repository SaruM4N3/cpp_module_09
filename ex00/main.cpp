/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:27:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/20 21:30:19 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
		std::cout <<"Error: could not open file"<< std::endl;
		return 1;
    }
	std::ifstream BitcoinData("data.csv");
	if (!BitcoinData.is_open()){std::cout <<"Error: could not open file"<< std::endl;return 1;};
	std::ifstream InputData(av[1]);
	if (!InputData.is_open()){std::cout <<"Error: could not open file"<< std::endl;return 1;};
	std::string firstLine;
	getline(InputData, firstLine);
	if (firstLine.compare("date | value") != 0)
	{
		std::cout << "Error: Wrong format line in input file. (should be: \"date | value\")" << std::endl;
		return 1;
	}
	getline(BitcoinData, firstLine);
	if (firstLine.compare("date,exchange_rate") != 0)
	{
		std::cout << "Error: Wrong format line in BitcoinCsv file. (should be: \"date,exchange_rate\")" << std::endl;
		return 1;
	}
	BitcoinExchange be;
	be.ProcessInputFile(InputData, BitcoinData);
	return 0;
}
