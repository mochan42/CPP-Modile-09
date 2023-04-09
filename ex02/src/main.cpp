/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 11:05:39 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h" 

int main(int argc, char **argv)
{
	int			b_input_nok;
	PmergeMe	collection;
	bool		hasDuplicate;

	b_input_nok = checkInput(argc, argv);
	if (b_input_nok > 0)
	{
		std::cout << RED << "Error: Input not correct." << D << "\n";
		return (0);
	}
	collection.storeCollection(argc, argv);
	hasDuplicate = collection.checkDuplicate();
	if (hasDuplicate == true)
	{
		std::cout << RED << "Error: Input has duplicates." << D << "\n";
		return (0);
	}
	std::cout << "Before:\t";
	collection.printInputVector();
	// std::cout << "before\t: ";
	// collection.printInputList();
	struct timeval start, end;
    gettimeofday(&start, NULL);
	vectFJMIsort(collection.getInputVector(), 0, collection.getInputVector().size() - 1);
	gettimeofday(&end, NULL);
	double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
	std::cout << "After:\t";
	collection.printInputVector();
	std::cout << "Time to process a range of " << collection.getInputVector().size() << " elements with std::vector<int> : " << std::fixed << time_taken * 1000000 << std::setprecision(5) << " usec\n";
	return (0);
}