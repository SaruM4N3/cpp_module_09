#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << CYAN << "Default constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

PmergeMe::PmergeMe(std::string name)
{
    std::cout << CYAN << "Paramaterized constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    std::cout << CYAN << "Copy constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
        this->_name = copy._name;
    std::cout << CYAN << "Copy assignment operator called on "
              << GREEN << this->_name
              << RESET << std::endl;
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << RED << "Destructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}