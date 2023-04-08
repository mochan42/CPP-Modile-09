/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:21:01 by mochan            #+#    #+#             */
/*   Updated: 2023/04/08 17:56:21 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

//======== CONSTRUCTORS =========================================================================
PmergeMe::PmergeMe()
{
	// std::cout << BLU << "Default constructor called from PmergeMe" << D << "\n";
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	// std::cout << BLU << "Copy constructor called from PmergeMe" << D << "\n";
	*this = src;
}


//======== OVERLOAD OPERATORS ===================================================================
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	// std::cout << BLU << "Copy assignment operator called from PmergeMe" << D << "\n";
	(void) src;
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
PmergeMe::~PmergeMe()
{
	// std::cout << CY << "Destructor called from PmergeMe" << D << "\n";
}


//======== GETTER / SETTER ======================================================================


//======== MEMBER FUNCTIONS =====================================================================


//======== FUNCTIONS ============================================================================
