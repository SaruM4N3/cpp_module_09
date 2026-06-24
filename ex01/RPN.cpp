/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:31:37 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/24 20:40:06 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void)copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	return *this;
}

RPN::~RPN()
{
}

static bool isOperator(char c)
{
	std::string operators = "/*-+";
	if (operators.find(c) != std::string::npos)
		return true;
	return false;
}

std::string RPN::ParseInput(std::string input)
{
	if (input.find_first_not_of("0123456789/*-+ ") != std::string::npos)
		throw std::runtime_error("Error");
	return input;
}

static int Calculus(char oper, int first, int second)
{
	int result = 0;
	switch (oper)
	{
	case '/':
		if (second == 0)
			throw std::runtime_error("Error");
		result = first / second;
		break;
	case '*':
		result = first * second;
		break;
	case '-':
		result = first - second;
		break;
	case '+':
		result = first + second;
		break;
	default:
		break;
	}
	return result;
}

void RPN::ProcessInput(std::string input)
{
	std::stack<int> stck;
	std::istringstream iss(input);
	std::string tokens;
	int result = 0;
	while (iss >> tokens)
	{
		if (tokens.size() != 1)
			throw std::runtime_error("Error");
		if (!isOperator(tokens[0]))
		{
			stck.push(tokens[0] - '0');
		}
		else
		{
			if (stck.size() < 2)
				throw std::runtime_error("Error");
			int b = stck.top();
			stck.pop();
			int a = stck.top();
			stck.pop();
			result = Calculus(tokens[0], a, b);
			stck.push(result);
		}
	}
	if (stck.size() != 1)
		throw std::runtime_error("Error");
	std::cout << stck.top() << std::endl;
}
