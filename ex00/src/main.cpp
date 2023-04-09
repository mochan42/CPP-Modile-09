/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/09 22:39:23 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Error: could not open file." << D << "\n";
		return (0);
	}
	BitcoinExchange	btcXchange;

	btcXchange.storeDatabase((char *)"data.csv");
	btcXchange.printBtcValue(av[1]);
	return (0);
}