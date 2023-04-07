/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 12:32:13 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	BitcoinExchange btcXchange;

	std::string infile = "data.csv";
	btcXchange.storeDatabase(infile);
	std::map<std::string, int> exchangeRateMap = btcXchange.getExchangeRateMap();
	std::for_each(exchangeRateMap.begin(), exchangeRateMap.end(), printExchangeRate);

	return (0);
}