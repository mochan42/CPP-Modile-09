/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/10 10:05:43 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h" 

int main(int argc, char **argv)
{
	PmergeMe	collection;

	if (checkInput(argc, argv) > 0)
	{
		std::cout << RED << "Error: Input not correct." << D << "\n";
		return (0);
	}
	collection.storeCollection(argc, argv);
	if (collection.checkDuplicate())
	{
		std::cout << RED << "Error: Input has duplicates." << D << "\n";
		return (0);
	}
	std::cout << "Before:\t";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	struct timeval	start_1, end_1;
	struct timeval	start_2, end_2;
    gettimeofday(&start_1, NULL);
	collection.mergeSort(collection.getVector(), 0, collection.getVector().size() - 1);
	gettimeofday(&end_1, NULL);
	gettimeofday(&start_2, NULL);
	collection.mergeSort(collection.getDeque(), 0, collection.getDeque().size() - 1);
	gettimeofday(&end_2, NULL);
	double time_taken_1 = (end_1.tv_sec - start_1.tv_sec) + (end_1.tv_usec - start_1.tv_usec) / 1000000.0;
	double time_taken_2 = (end_2.tv_sec - start_2.tv_sec) + (end_2.tv_usec - start_2.tv_usec) / 1000000.0;
	std::cout << "After:\t";
	collection.printVector();
	std::cout << "Time to process a range of " << collection.getVector().size() << " elements with std::vector<int> : " << std::fixed << time_taken_1 * 1000000 << std::setprecision(10) << " usec\n";
	std::cout << "Time to process a range of " << collection.getDeque().size() << " elements with std::deque<int> : " << std::fixed << time_taken_2 * 1000000 << std::setprecision(10) << " usec\n";	
	return (0);
}