/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:20:54 by mochan            #+#    #+#             */
/*   Updated: 2023/04/08 18:29:28 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

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

int main(int argc, char **argv)
{
	int		b_input_nok;

	b_input_nok = check_input(argc, argv);
	if (b_input_nok > 0)
		std::cout << RED << "Error: Input not correct." << D << "\n";
	return (0);
}