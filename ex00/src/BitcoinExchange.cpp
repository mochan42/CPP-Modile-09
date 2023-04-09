/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:51 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/09 22:18:25 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

//======== CONSTRUCTORS =========================================================================
BitcoinExchange::BitcoinExchange() :
	_btcExchangeRate(std::map<std::string, float>())
{
	// std::cout << BLU << "Default constructor called from BitcoinExchange" << D << "\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	// std::cout << BLU << "Copy constructor called from BitcoinExchange" << D << "\n";
	*this = src;
}


//======== OVERLOAD OPERATORS ===================================================================
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	// std::cout << BLU << "Copy assignment operator called from BitcoinExchange" << D << "\n";
	if (this != &src)
	{
		new (this) BitcoinExchange(src);
	}
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << CY << "Destructor called from BitcoinExchange" << D << "\n";
}


//======== GETTER / SETTER ======================================================================
void	BitcoinExchange::setExchangeRate(const std::pair<std::string, float>& setExchangeRate)
{
	 this->_btcExchangeRate.insert(setExchangeRate);
}

std::map<std::string, float>	BitcoinExchange::getExchangeRateMap()
{
	return _btcExchangeRate;
}


//======== MEMBER FUNCTIONS =====================================================================

void	BitcoinExchange::checkFileCanBeOpened(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cout << RED << "Error:file could not be opened" << D << "\n";
		return ;
	}
}

void	BitcoinExchange::storeDatabase(char* infilePath)
{
	std::ifstream infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		size_t	pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "Error: delimiter not found in line \"" << line << "\"" << std::endl;
			continue;
		}
		std::string	date = line.substr(0, pos);
		std::string	numericValue = line.substr(pos + 1); // +1 is for length of comma delimiter.
		float btcNumericValueInt = static_cast<float>(atof(numericValue.c_str()));
		this->_btcExchangeRate.insert(std::pair<std::string, float > (date, btcNumericValueInt));
	}
	infile.close();
}

float	BitcoinExchange::findBtcRate(std::string date)
{
	float		btcCoinRate = 0;
	bool		dateFound = false;
	std::string	closestEarlierDate;
	float		closestEarlierRate = 0;
	std::map<std::string, float>::const_iterator it; // declare a const_iterator for the map

	for (it = _btcExchangeRate.begin(); it != _btcExchangeRate.end(); it++)
	{
		if (it->first < date) // check if the current date in the map is earlier than the desired date
		{
			if (closestEarlierDate.empty() || closestEarlierDate < it->first) // check if this date is closer than the previously found closest date
			{
				closestEarlierDate = it->first;
				closestEarlierRate = it->second;
			}
		}
		else if (it->first == date)
		{
			btcCoinRate = it->second;
			dateFound = true;
			break;
		}
	}
	if (dateFound == false)
	{
		if (!closestEarlierDate.empty())
			btcCoinRate = closestEarlierRate;
		else
			btcCoinRate = 0;
	}
	return (btcCoinRate);
}

void	BitcoinExchange::printBtcValue(char* infilePath)
{
	std::ifstream infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		const std::string& delimiter = " | ";
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			std::cout << RED << "Error: bad input => " << line << D << "\n";
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string btcCoinsNumber = line.substr(pos + delimiter.length());

		float btcCoinsNumberInt = static_cast<float>(atof(btcCoinsNumber.c_str()));
		if (btcCoinsNumberInt < 0)
		{
			std::cout << RED << "Error: not a positive number." << D << "\n";
			continue;
		}
		if (static_cast<long>(btcCoinsNumberInt) > static_cast<long>(MAX_INT))
		{
			std::cout << RED << "Error: too large a number." << D << "\n";
			continue;
		}
		float btcCoinRate = 0;
		btcCoinRate = findBtcRate(date);
		std::cout << date << " => " << btcCoinsNumberInt << " = " << static_cast<float>(btcCoinsNumberInt * btcCoinRate) << "\n";
	}
	infile.close();
}


//======== FUNCTIONS ============================================================================
void	printExchangeRate(const std::pair<std::string, float>& exchangeRate)
{
	std::cout << exchangeRate.first << " , " << exchangeRate.second << "\n";
}