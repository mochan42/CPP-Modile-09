/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 09:45:45 by moninechan       ###   ########.fr       */
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
	std::cout << "before : ";
	collection.printInputVector();
	std::cout << "before : ";
	collection.printInputList();

	return (0);
}