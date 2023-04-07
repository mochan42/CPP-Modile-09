/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 14:35:21 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (0);
	}
	BitcoinExchange btcXchange;

	std::string inputfilePath = av[1];
	std::ifstream inputFile(inputfilePath);
	if (!inputFile.is_open())
	{
		std::cout << RED << "Error: input file could not be opened" << D << "\n";
		return (0);
	}
	btcXchange.storeInput(inputfilePath);
	std::map<std::string, int> inputMap = btcXchange.getInputMap();
	std::for_each(inputMap.begin(), inputMap.end(), printExchangeRate);

	// std::string databaseFile = "data.csv";
	// btcXchange.storeDatabase(databaseFile);
	// std::map<std::string, int> exchangeRateMap = btcXchange.getExchangeRateMap();
	// std::for_each(exchangeRateMap.begin(), exchangeRateMap.end(), printExchangeRate);
	inputFile.close();
	return (0);
}