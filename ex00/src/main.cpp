/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 12:41:33 by mochan           ###   ########.fr       */
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

	std::string infile = av[1];
	btcXchange.storeDatabase(infile);
	std::map<std::string, int> exchangeRateMap = btcXchange.getExchangeRateMap();
	std::for_each(exchangeRateMap.begin(), exchangeRateMap.end(), printExchangeRate);
	return (0);
}