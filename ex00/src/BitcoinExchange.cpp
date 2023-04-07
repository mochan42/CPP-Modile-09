/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:51 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 12:47:35 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() :
	_btcExchangeRate(std::map<std::string, int>())
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
	if (this != &src)
	{
		new (this) BitcoinExchange(src);
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << CY << "Destructor called from BitcoinExchange" << D << "\n";
}

void    BitcoinExchange::setExchangeRate(const std::pair<std::string, int>& exchangeRate)
{
	 this->_btcExchangeRate.insert(exchangeRate);
}

void	printExchangeRate(const std::pair<std::string, int>& exchangeRate)
{
	std::cout << exchangeRate.first << " | " << exchangeRate.second << "\n";
}

std::map<std::string, int>	BitcoinExchange::getExchangeRateMap()
{
	return _btcExchangeRate;
}

void    BitcoinExchange::storeDatabase(const std::string& infilePath)
{
	std::ifstream infile(infilePath);
	if (!infile.is_open())
	{
		std::cout << RED << "Error:file could not be opened" << D << "\n";
		return ;
	}

	std::string	line;
	std::string	parsedLine;
    std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		char	*ptrDate;
		char	*ptrBtcExchangeRate;
		char	*linePtr = &line[0];
		std::cout << linePtr << "\n";
		int		btcExchangeRateInt;
		ptrDate = std::strtok(linePtr, " , "); // return pointer to 1st token (Date), replace the first token with '\0'
		ptrBtcExchangeRate = strtok (NULL, " , "); // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
		btcExchangeRateInt = atoi(ptrBtcExchangeRate);
		this->_btcExchangeRate.insert(std::pair<std::string, int > (ptrDate, btcExchangeRateInt));
	}
	infile.close();
}