/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:42 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 09:31:21 by moninechan       ###   ########.fr       */
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

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
		
		std::vector<int>&	getInputVector();
		std::list<int>&		getInputList();
		void				addNumberToVector(int setNumberValue);
		void				addNumberToList(int setNumberValue);
		void				storeCollection(int argc,char **argv);
		bool				checkDuplicate();
		void				printInputVector();
		void				printInputList();

	private:
		std::vector<int>	_inputVector;
		std::list<int>		_inputList;
};

int		check_for_not_a_digit(char *s);
int		out_of_range_number(char *s);
int		check_input_method_2(int n, char **args);
int		check_input(int argc, char **argv);

#endif