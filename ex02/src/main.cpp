/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 10:59:32 by moninechan       ###   ########.fr       */
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
	clock_t start = clock();
	vectFJMIsort(collection.getInputVector(), 0, collection.getInputVector().size() - 1);
	clock_t end = clock();
	double time_taken = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "After:\t";
	collection.printInputVector();
	std::cout << "Time to process a range of " << collection.getInputVector().size() << " elements with std::vector<int> : " << std::fixed << time_taken * 1000000 << std::setprecision(5) << " usec\n";
	return (0);
}