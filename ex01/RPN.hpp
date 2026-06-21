/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:31:33 by zsonie            #+#    #+#             */
/*   Updated: 2026/06/20 23:01:11 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
public:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();

	std::string ParseInput(std::string input);
	void ProcessInput(std::string input);
};

#endif