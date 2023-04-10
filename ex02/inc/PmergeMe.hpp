/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:42 by mochan            #+#    #+#             */
/*   Updated: 2023/04/10 10:09:03 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <cstring>
# include <vector>
# include <list>
# include <deque>
# include <set>
# include <iomanip> // for setprecision
# include <sys/time.h>

class	PmergeMe
{
	private:
		std::vector<int>	_inputVector;
		std::deque<int>		_inputDeque;
		void				addNumberToVector(int setNumberValue);
		void				addNumberToDeque(int setNumberValue);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		std::vector<int>&	getVector();
		std::deque<int>&	getDeque();
		void				storeCollection(int argc, char **argv);
		bool				checkDuplicate();
		void				printVector();
		void				printDeque();
		
		template <typename T>
		void	insertionSort(T& A, int first, int middle)
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
		}

		template <typename T>
		void	merge(T& A, int first, int middle, int last)
		{
			int n1 = middle - first + 1; // length of left array n1 = 3
			int n2 = last - middle; // length of right array  n2 = 2
			int LA[n1]; // declare Left Array
			int RA[n2]; // declare Right Array
			for (int i = 0; i < n1; i++) // copy values from A into LA
				LA[i] = A[first + i];
			for (int i = 0; i < n2; i++) // copy values from A into RA
				RA[i] = A[middle + 1 + i];
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

		template <typename T>
		void mergeSort(T& A, int first, int last)
		{
			int n = last - first + 1;
			if (n > 2) // K == 2 since we want to pair the values into sub-arrays of size 2
			{
				int middle = (first + last) / 2; // 1st. iteration q = 0 + n - 1 / 2
				mergeSort(A, first, middle); // 2nd. sort it 0 -> middle | left hand side
				mergeSort(A, middle + 1, last); // 3rd. it middle -> n - 1 | right hand side
				merge(A, first, middle, last);
			}
			else
				insertionSort(A, first, last);
		}
};

int		checkIsDigit(char *s);
int		checkOutOfRange(char *s);
int		checkIsDigitAndOutOfRange(int n, char **args);
int		checkInput(int argc, char **argv);

#endif