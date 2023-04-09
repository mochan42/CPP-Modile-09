/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:21:01 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 09:31:01 by moninechan       ###   ########.fr       */
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
std::vector<int>&	PmergeMe::getInputVector()
{
	return this->_inputVector;
}

std::list<int>&		PmergeMe::getInputList()
{
	return this->_inputList;
}


//======== MEMBER FUNCTIONS =====================================================================
void	PmergeMe::addNumberToVector(int setNumberValue)
{
	this->_inputVector.push_back(setNumberValue);
}

void	PmergeMe::addNumberToList(int setNumberValue)
{
	this->_inputList.push_back(setNumberValue);
}

void	PmergeMe::storeCollection(int argc, char **argv)
{
	int	i = 1;
	int	value = 0;

	while (i < argc)
	{
		value = atoi(argv[i]);
		addNumberToVector(value);
		addNumberToList(value);
		i++;
	}	
}


void	PmergeMe::printInputVector()
{
	std::vector<int>::iterator it;

	std::cout << "std::vector\t: ";
	for (it = getInputVector().begin(); it != getInputVector().end(); it++)
	{
		std::cout << *it << " - ";
	}
	std::cout << "\n";
}

void	PmergeMe::printInputList()
{
	std::list<int>::iterator it;

	std::cout << "std::list\t: ";
	for (it = getInputList().begin(); it != getInputList().end(); it++)
	{
		std::cout << *it << " - ";
	}
	std::cout << "\n";
}

bool	PmergeMe::checkDuplicate()
{
	bool hasDuplicate = false;
    std::set<int> set(getInputVector().begin(), getInputVector().end()); // copy elements of vec into a set

    if (set.size() == getInputVector().size())
        hasDuplicate = false;
    else
        hasDuplicate = true;
	return (hasDuplicate);
}


//======== FUNCTIONS ============================================================================
int	check_for_not_a_digit(char *s)
{
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s)
	{
		if (isdigit(*s) != 1)
			return (1);
		s++;
	}
	return (0);
}

int	out_of_range_number(char *s)
{
	long	c;

	c = strtol(s, NULL, 10);
	if (c < MIN_INT || c > MAX_INT || strlen(s) > 11)
		return (1);
	return (0);
}

int	check_input_method_2(int n, char **args)
{
	int	i;
	int	err_1;
	int	err;

	i = 1;
	err = 0;
	while (i < n)
	{
		err_1 = check_for_not_a_digit(args[i]) + out_of_range_number(args[i]);
		err = err + err_1;
		i++;
	}
	return (err);
}

int	check_input(int argc, char **argv)
{
	int		err;

	err = 0;
	if (argc == 1)
		;
	if (argc > 1)
		err = check_input_method_2(argc, argv);
	return (err);
}

//======== ALGO ============================================================================

const int K = 2;

void insertionSort(int A[], int first, int middle)
{
    for (int i = first; i < middle; i++)
    {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > first && A[j - 1] > tempVal)
		{
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    std::vector<int> temp(A + first, A + middle + 1);
    for (size_t i = 0; i < temp.size(); i++) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

// A = {5, 4, 3, 2, 1}
void merge(int A[], int first, int middle, int last)
{
	int n1 = middle - first + 1; // length of left array n1 = 3
	int n2 = last - middle; // length of right array  n2 = 2
	int LA[n1]; // declare Left Array
	int RA[n2]; // declare Right Array
	for (int i = 0; i < n1; i++) // copy values from A into LA
	{
		LA[i] = A[first + i]; // LA = {5, 4, 3}
	}
	for (int i = 0; i < n2; i++) // copy values from A into RA
	{
		RA[i] = A[middle + 1 + i]; // RA = {2, 1}
	}
	int RIDX = 0; // right index
	int LIDX = 0; // left index
	for (int i = first; i <= last; i++)
	{
		if (RIDX == n2) // reached end of right hand side Array
		{
			A[i] = LA[LIDX]; // left hand side index into A[i]
			LIDX++;
		}
		else if (LIDX == n1)
		{
			A[i] = RA[RIDX];
			RIDX++;
		}
		else if (RA[RIDX] > LA[LIDX]) // not true for RA{2} LA{5}
		{
			A[i] = LA[LIDX];
			LIDX++;
		}
		else // We are copying the SMALLEST value into A[i]
		{
			A[i] = RA[RIDX]; // A[0] = RA[0] => A = {2, 4, 3, 2, 1}
			RIDX++;
		}
	}
}

void sort(int A[], int first, int last)
{
    int n = last - first + 1;
    if (n > K) // K == 2 since we want to pair the values into sub-arrays of size 2
    {
        int middle = (first + last) / 2; // 1st. iteration q = 0 + n - 1 / 2
        sort(A, first, middle); // 2nd. sort it 0 -> middle | left hand side
        sort(A, middle + 1, last); // 3rd. it middle -> n - 1 | right hand side
        merge(A, first, middle, last);
    }
    else
        insertionSort(A, first, last);
}
