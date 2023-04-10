/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:21:01 by mochan            #+#    #+#             */
/*   Updated: 2023/04/10 10:33:27 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include "PmergeMe.hpp"

//======== CONSTRUCTORS =========================================================================
PmergeMe::PmergeMe() : _inputVector(), _inputDeque()
{
}

PmergeMe::PmergeMe(const PmergeMe& src) :
	_inputVector(src._inputVector), _inputDeque(src._inputDeque)
{
}

//======== OVERLOAD OPERATORS ===================================================================
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != & src) // check for self assignment
	{
		this->_inputVector.clear();
		this->_inputVector.insert(this->_inputVector.begin(), src._inputVector.begin(), src._inputVector.end());
		this->_inputDeque.clear();
		this->_inputDeque.insert(this->_inputDeque.begin(), src._inputDeque.begin(), src._inputDeque.end());
	}
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
PmergeMe::~PmergeMe()
{
}

//======== GETTERS / SETTERS ====================================================================
std::vector<int>&	PmergeMe::getVector()
{
	return this->_inputVector;
}

std::deque<int>&	PmergeMe::getDeque()
{
	return this->_inputDeque;
}

//======== MEMBER FUNCTIONS =====================================================================
void	PmergeMe::addNumberToVector(int setNumberValue)
{
	this->_inputVector.push_back(setNumberValue);
}

void	PmergeMe::addNumberToDeque(int setNumberValue)
{
	this->_inputDeque.push_back(setNumberValue);
}

void	PmergeMe::storeCollection(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		addNumberToVector(atoi(argv[i]));
		addNumberToDeque(atoi(argv[i]));
	}
}

void	PmergeMe::printVector()
{
	for (std::vector<int>::iterator it = getVector().begin(); it != getVector().end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

void	PmergeMe::printDeque()
{
	for (long unsigned int i = 0; i < this->getDeque().size(); i++)
		std::cout << this->getDeque()[i] << " ";
	std::cout << "\n";
}

bool	PmergeMe::checkDuplicate()
{
    std::set<int> set(getVector().begin(), getVector().end()); // copy elements of vec into a set

    if (set.size() == getVector().size())
		return (false);
	return (true);
}

//======== FUNCTIONS ============================================================================

int	checkIsDigit(char *s)
{
	int i = 0;

	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (isdigit(s[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	checkOutOfRange(char *s)
{
	long	c;

	c = strtol(s, NULL, 10);
	if (c < MIN_INT || c > MAX_INT || strlen(s) > 11)
		return (1);
	return (0);
}

int	checkIsDigitAndOutOfRange(int n, char **args)
{
	int	i;
	int	err_1;
	int	err;

	i = 1;
	err = 0;
	while (i < n)
	{
		err_1 = checkIsDigit(args[i]) + checkOutOfRange(args[i]);
		err = err + err_1;
		i++;
	}
	return (err);
}

int	checkInput(int argc, char **argv)
{
	int		err;

	err = 0;
	if (argc == 1)
		return (0);
	if (argc > 1)
		err = checkIsDigitAndOutOfRange(argc, argv);
	return (err);
}	