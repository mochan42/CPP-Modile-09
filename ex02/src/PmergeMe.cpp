/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:21:01 by mochan            #+#    #+#             */
/*   Updated: 2023/04/08 19:04:34 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

//======== CONSTRUCTORS =========================================================================
PmergeMe::PmergeMe() :
	_inputVector(), _inputList()
{
	// std::cout << BLU << "Default constructor called from PmergeMe" << D << "\n";
}

PmergeMe::PmergeMe(const PmergeMe& src) :
	_inputVector(src._inputVector), _inputList(src._inputList)
{
	// std::cout << BLU << "Copy constructor called from PmergeMe" << D << "\n";
}


//======== OVERLOAD OPERATORS ===================================================================
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	// std::cout << BLU << "Copy assignment operator called from PmergeMe" << D << "\n";
	if (this != & src) // check for self assignment
	{
		this->_inputVector.clear();
		this->_inputVector.insert(this->_inputVector.begin(), src._inputVector.begin(), src._inputVector.end());
		this->_inputList.clear();
		this->_inputList.insert(this->_inputList.begin(), src._inputList.begin(), src._inputList.end());
	}
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
PmergeMe::~PmergeMe()
{
	// std::cout << CY << "Destructor called from PmergeMe" << D << "\n";
}


//======== GETTER / SETTER ======================================================================
std::vector<int>	PmergeMe::getInputVector()
{
	return _inputVector;
}

//======== MEMBER FUNCTIONS =====================================================================
void	PmergeMe::addNumberToVector(int setNumberValue)
{
	this->_inputVector.push_back(setNumberValue);
}

void	PmergeMe::storeCollectiontoVector(char **argv)
{
	int	i = 1;
	int	value = 0;

	while (argv[i] != NULL)
	{
		value = atoi(argv[i]);
		addNumberToVector(value);
		i++;
	}	
}

void	PmergeMe::printInputVector()
{
	std::vector<int>::iterator it;

	for (it = getInputVector().begin(); it != getInputVector().end(); it++)
	{
		std::cout << *it << " - ";
	}
}


//======== FUNCTIONS ============================================================================
