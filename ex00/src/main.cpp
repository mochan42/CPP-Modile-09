/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/08 16:57:37 by mochan           ###   ########.fr       */
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

	std::string		databaseFile = "data.csv";	
	btcXchange.storeDatabase(databaseFile);
	std::map<std::string, float> input = btcXchange.getInputMap();
	std::string		inputfilePath = av[1];
	btcXchange.printBtcValue(inputfilePath);
	return (0);
}