#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#pragma once
#include <iostream>
#include <string>
#include "colors.hpp"

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(std::string name);
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

private:
    std::string    _name;
};

#endif