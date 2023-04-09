/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/09 09:28:39 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h" 

int	check_for_duplicate(int argc, char **argv)
{
	int	*list_of_numbers;
	int	i;
	int	j;
	int	b_duplicate;

	b_duplicate = 0;
	list_of_numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (list_of_numbers == NULL)
		return (1);
	i = -1;
	while (++i < argc - 1)
		list_of_numbers[i] = atoi(argv[i + 1]);
	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 1)
			if (list_of_numbers[i] == list_of_numbers[j])
				b_duplicate = 1;
	}
	free(list_of_numbers);
	list_of_numbers = NULL;
	return (b_duplicate);
}


int main(int argc, char **argv)
{
	int			b_input_nok;
	PmergeMe	collection;
	bool		hasDuplicate;

	b_input_nok = check_input(argc, argv);
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