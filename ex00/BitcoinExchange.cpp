/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:28:53 by zsonie            #+#    #+#             */
/*   Updated: 2026/05/14 22:28:54 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << CYAN << "Default constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string name)
{
    std::cout << CYAN << "Paramaterized constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << CYAN << "Copy constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->_name = copy._name;
    std::cout << CYAN << "Copy assignment operator called on "
              << GREEN << this->_name
              << RESET << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << RED << "Destructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}