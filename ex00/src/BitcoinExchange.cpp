/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:51 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 07:58:56 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"


BitcoinExchange::BitcoinExchange()
{
    std::cout << BLU << "Default constructor called from BitcoinExchange" << D << "\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    std::cout << BLU << "Copy constructor called from BitcoinExchange" << D << "\n";
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    std::cout << BLU << "Copy assignment operator called from BitcoinExchange" << D << "\n";
    this->btcExchangeRate = src.btcExchangeRate;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << CY << "Destructor called from BitcoinExchange" << D << "\n";
}

void    BitcoinExchange::storeDatabase(const std::string& inputFilePath)
{
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open())
    {
    	std::cout << RED << "Error:file could not be opened" << D << "\n";
		return ;
    }

	std::string	line;
	std::string	parsedLine;
    std::getline(inputFile, line); // Skip the first line
	while(getline(inputFile, line))
	{
		char	*ptrDate;
		char	*ptrBtcExchangeRate;
		char	*linePtr = &line[0];
		int		btcExchangeRateInt;
		ptrDate = std::strtok(linePtr, " , "); // return pointer to 1st token (Date), replace the first token with '\0'
		ptrBtcExchangeRate = strtok (NULL, " , "); // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
		btcExchangeRateInt = atoi(ptrBtcExchangeRate);
		btcExchangeRate.insert(std::pair<std::string, int > (ptrDate, btcExchangeRateInt));
	}
    inputFile.close();
}