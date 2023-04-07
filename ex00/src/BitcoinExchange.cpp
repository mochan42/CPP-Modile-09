/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:51 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 19:21:15 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() :
	_btcExchangeRate(std::map<std::string, int>()), _input(std::map<std::string, int>())
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

void    BitcoinExchange::setInput(const std::pair<std::string, int>& setInput)
{
	 this->_input.insert(setInput);
}

std::map<std::string, int>	BitcoinExchange::getInputMap()
{
	return _input;
}

void    BitcoinExchange::setExchangeRate(const std::pair<std::string, int>& setExchangeRate)
{
	 this->_btcExchangeRate.insert(setExchangeRate);
}

std::map<std::string, int>	BitcoinExchange::getExchangeRateMap()
{
	return _btcExchangeRate;
}

void	printExchangeRate(const std::pair<std::string, int>& exchangeRate)
{
	std::cout << exchangeRate.first << " , " << exchangeRate.second << "\n";
}

void	BitcoinExchange::storeMap(const std::string& targetMap, const std::string& infilePath, const std::string& delimiter)
{
	std::ifstream infile(infilePath);
	if (!infile.is_open())
	{
		std::cout << RED << "Error:file could not be opened" << D << "\n";
		return ;
	}

	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			std::cout << "Error: delimiter not found in line \"" << line << "\"" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string numericValue = line.substr(pos + delimiter.length());
		int btcNumericValueInt = atoi(numericValue.c_str());
		if (targetMap == "_input")
			this->_input.insert(std::pair<std::string, int > (date, btcNumericValueInt));
		if (targetMap == "_btcExchangeRate")
			this->_btcExchangeRate.insert(std::pair<std::string, int > (date, btcNumericValueInt));
	}
	infile.close();
}

void	BitcoinExchange::printBtcValue(const std::string& infilePath)
{
	std::ifstream infile(infilePath);
	if (!infile.is_open())
	{
		std::cout << RED << "Error: input file could not be opened" << D << "\n";
		return ;
	}
	
	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		const std::string& delimiter = " | ";
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			std::cout << "Error: delimiter not found in line \"" << line << "\"" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string btcCoinsNumber = line.substr(pos + delimiter.length());

		int btcCoinsNumberInt = atoi(btcCoinsNumber.c_str());
		int btcCoinRate = 0;
		
		std::map<std::string, int>::const_iterator it; // declare a const_iterator for the map

		for (it = _btcExchangeRate.begin(); it != _btcExchangeRate.end(); it++)
		{
			if (it->first == date)
			{
				btcCoinRate = it->second;
				break;
			}
		}
		std::cout << date << " | " << btcCoinsNumberInt * btcCoinRate << "\n";
	}
		
	infile.close();
}


// void	BitcoinExchange::storeMap(const std::string& targetMap, const std::string& infilePath, const char* delimiter)
// {
// 	std::ifstream infile(infilePath);
// 	if (!infile.is_open())
// 	{
// 		std::cout << RED << "Error:file could not be opened" << D << "\n";
// 		return ;
// 	}

// 	std::string	line;
// 	std::string	parsedLine;
//     std::getline(infile, line); // Skip the first line
// 	while(getline(infile, line))
// 	{
// 		char	*ptrDate;
// 		char	*ptrBtcNumericValue;
// 		char	*linePtr = &line[0];
// 		int		btcNumericValueInt;
// 		if (!(ptrDate = std::strtok(linePtr, delimiter))) // return pointer to 1st token (Date), replace the first token with '\0'
// 			continue;
// 		if (!(ptrBtcNumericValue = strtok (NULL, delimiter))) // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
// 			continue;
// 		else
// 			btcNumericValueInt = atoi(ptrBtcNumericValue);
// 		if (targetMap == "_input")
// 			this->_input.insert(std::pair<std::string, int > (ptrDate, btcNumericValueInt));
// 		if (targetMap == "_btcExchangeRate")
// 			this->_btcExchangeRate.insert(std::pair<std::string, int > (ptrDate, btcNumericValueInt));
// 	}
// 	infile.close();
// }


// void    BitcoinExchange::storeDatabase(const std::string& infilePath)
// {
// 	std::ifstream infile(infilePath);
// 	if (!infile.is_open())
// 	{
// 		std::cout << RED << "Error:file could not be opened" << D << "\n";
// 		return ;
// 	}

// 	std::string	line;
// 	std::string	parsedLine;
//     std::getline(infile, line); // Skip the first line
// 	while(getline(infile, line))
// 	{
// 		char	*ptrDate;
// 		char	*ptrBtcExchangeRate;
// 		char	*linePtr = &line[0];
// 		std::cout << linePtr << "\n";
// 		int		btcExchangeRateInt;
// 		ptrDate = std::strtok(linePtr, " , "); // return pointer to 1st token (Date), replace the first token with '\0'
// 		ptrBtcExchangeRate = strtok (NULL, " , "); // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
// 		btcExchangeRateInt = atoi(ptrBtcExchangeRate);
// 		this->_btcExchangeRate.insert(std::pair<std::string, int > (ptrDate, btcExchangeRateInt));
// 	}
// 	infile.close();
// }

// void    BitcoinExchange::storeInput(const std::string& infilePath)
// {
// 	std::ifstream infile(infilePath);
// 	if (!infile.is_open())
// 	{
// 		std::cout << RED << "Error:file could not be opened" << D << "\n";
// 		return ;
// 	}

// 	std::string	line;
// 	std::string	parsedLine;
//     std::getline(infile, line); // Skip the first line
// 	while(getline(infile, line))
// 	{
// 		char	*ptrDate;
// 		char	*ptrBtcExchangeRate;
// 		char	*linePtr = &line[0];
// 		std::cout << linePtr << "\n";
// 		int		btcExchangeRateInt;
// 		if (!(ptrDate = std::strtok(linePtr, " | "))) // return pointer to 1st token (Date), replace the first token with '\0'
// 			continue;
// 		if (!(ptrBtcExchangeRate = strtok (NULL, " | "))) // replace '\0' with delimiter, returns pointer to next token (BtcExchangeRate). 
// 			continue;
// 		else
// 			btcExchangeRateInt = atoi(ptrBtcExchangeRate);
// 		this->_btcExchangeRate.insert(std::pair<std::string, int > (ptrDate, btcExchangeRateInt));
// 	}
// 	infile.close();
// }