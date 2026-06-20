/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:28:53 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/20 21:56:17 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <map>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void) copy;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

static bool IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static bool CheckDateFormat(const std::string &date)
{
	if (date.size() != 10)
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	static const int daysInMonth[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && IsLeapYear(year))
		maxDay = 29;
	if (day > maxDay)
		return false;
	return true;
}

static bool ParseInputLine(const std::string &inputLine, std::string &date, double &value)
{
	size_t separator = inputLine.find(" | ");
	if (separator == std::string::npos)
		return false;

	date = inputLine.substr(0, separator);
	std::string valueStr = inputLine.substr(separator + 3);

	char *end;
	value = strtod(valueStr.c_str(), &end);
	if (end == valueStr.c_str() || *end != '\0')
		return false;
	return true;
}

static double GetValueFromDataLine(const std::string &inputDate, std::map<std::string, double> &rates)
{
	std::map<std::string, double>::iterator it = rates.lower_bound(inputDate);

	if (it != rates.end() && it->first == inputDate)
		return it->second;
	if (it == rates.begin())
		return -1;
	--it;
	return it->second;
}

static bool CheckValueFormat(double value)
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

static std::map<std::string, double> LoadDataFile(std::ifstream &dataFile)
{
	std::map<std::string, double> rates;
	std::string line;

	while (getline(dataFile, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = line.substr(0, comma);
		double value = strtod(line.c_str() + comma + 1, NULL);
		rates[date] = value;
	}
	return rates;
}

static int ProcessLine(const std::string &inputLine, std::map<std::string, double> &rates)
{
	std::string inputDate;
	double inputValue;

	if (!ParseInputLine(inputLine, inputDate, inputValue) || !CheckDateFormat(inputDate))
	{
		std::cout << "Error: bad input => " << inputLine << std::endl;
		return 1;
	}
	if (!CheckValueFormat(inputValue))
		return 1;

	double dataValue = GetValueFromDataLine(inputDate, rates);
	if (dataValue < 0)
	{
		std::cout << "Error: no data available for date " << inputDate << std::endl;
		return 1;
	}

	double result = dataValue * inputValue;
	std::cout << inputDate << " ==> " << inputValue << " = " << result << std::endl;
	return 0;
}

int BitcoinExchange::ProcessInputFile(std::ifstream &inputFile, std::ifstream &dataFile)
{
	std::map<std::string, double> rates = LoadDataFile(dataFile);
	std::string inputLine;

	while (getline(inputFile, inputLine))
		ProcessLine(inputLine, rates);
	return 0;
}
