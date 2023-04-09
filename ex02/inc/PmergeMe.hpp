/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:42 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 11:06:18 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <iomanip> // for setprecision
#include <sys/time.h>

class	PmergeMe
{
	public:
		// CANONICAL FORM
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
		
		// MEMBER FUNCTIONS
		std::vector<int>&	getInputVector();
		std::list<int>&		getInputList();
		void				addNumberToVector(int setNumberValue);
		void				addNumberToList(int setNumberValue);
		void				storeCollection(int argc,char **argv);
		bool				checkDuplicate();
		void				printInputVector();
		void				printInputList();

	private:
		// MEMBER ATTRIBUTES
		std::vector<int>	_inputVector;
		std::list<int>		_inputList;
};

int		checkIsDigit(char *s);
int		checkOutOfRange(char *s);
int		checkIsDigitAndOutOfRange(int n, char **args);
int		checkInput(int argc, char **argv);

// MERGE INSERTION SORT ALGORITHM FUNCTIONS
void	vectFJMIinsertionSort(std::vector<int>& A, int first, int middle);
void	vectFJMImerge(std::vector<int>& A, int first, int middle, int last);
void	vectFJMIsort(std::vector<int>& A, int first, int last);

#endif