/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/08 20:40:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h" 

void insertionSort(int A[], int p, int q)
{
	for (int i = p; i < q; i++) {
		int tempVal = A[i + 1];
		int j = i + 1;
		while (j > p && A[j - 1] > tempVal) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tempVal;
	}
	std::vector<int> temp(A + p, A + q + 1);
	for (size_t i = 0; i < temp.size(); i++) {
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;
}

void merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int LA[n1];
	int RA[n2];
	for (int i = 0; i < n1; i++)
		LA[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		RA[i] = A[q + 1 + i];
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++)
	{
		if (RIDX == n2) {
			A[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			A[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			A[i] = LA[LIDX];
			LIDX++;
		} else {
			A[i] = RA[RIDX];
			RIDX++;
		}
	}
}


// p is the index of the first element to sort in the collection.
// r is the index of the last element to sort in the collection.
void sort(int A[], int p, int r)
{
	std::cout << p ", " << r << "\n";
	int n = r - p + 1; //Size of the collection
	if (n > 2)
	{
		int q = (p + r) / 2;
		sort(A, p, q);
		sort(A, q + 1, r);
		merge(A, p, q, r);
	}
	else
	{
		insertionSort(A, p, r);
	}
}

int main(int argc, char **argv)
{
	int			b_input_nok;
	PmergeMe	collection;

	b_input_nok = check_input(argc, argv);
	if (b_input_nok > 0)
	{
		std::cout << RED << "Error: Input not correct." << D << "\n";
		return (0);
	}
	collection.storeCollection(argc, argv);
	std::cout << "before : ";
	collection.printInputVector();
	std::cout << "before : ";
	collection.printInputList();

	return (0);
}