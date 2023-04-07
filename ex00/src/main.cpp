/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 07:57:02 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	BitcoinExchange	btcXchange;
	
	std::string infile = "data.csv";
	btcXchange.storeDatabase(infile);
	std::map<std::string, int >::const_iterator it;
	for (it = btcXchange.btcExchangeRate.begin(); it != btcXchange.btcExchangeRate..end(); it++)
		std::cout << it->first << " | " << it->second << "\n";

	
    // if (!btcDatabase.is_open())
    // {
    // 	std::cout << RED << "Error:file could not be opened" << D << "\n";
	// 	return (0);
    // }
	
	

	
	// std::string	line;
	// std::string	parsedLine;
	// std::map<std::string, int> btcDatabaseMap;

    // std::getline(btcDatabase, line); // Skip the first line
	// while(getline(btcDatabase, line))
	// {
	// 	char	*ptrDate;
	// 	char	*ptrBtcExchangeRate;
	// 	char	*linePtr = &line[0];
	// 	int		btcExchangeRate;
	// 	ptrDate = std::strtok(linePtr, " , "); // return pointer to 1st token (Date), replace the first token with '\0'
	// 	ptrBtcExchangeRate = strtok (NULL, " , "); // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
	// 	btcExchangeRate = atoi(ptrBtcExchangeRate);
	// 	btcDatabaseMap.insert(std::pair<std::string, int > (ptrDate, btcExchangeRate));
	// }

	// std::map<std::string, int >::const_iterator it;
	// for (it = btcDatabaseMap.begin(); it != btcDatabaseMap.end(); it++)
	// 	std::cout << it->first << " | " << it->second << "\n";

	// btcDatabase.close();
	return (0);
}