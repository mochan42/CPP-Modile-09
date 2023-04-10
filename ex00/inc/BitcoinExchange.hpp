/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:47 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/10 09:22:53 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>  
#include <algorithm>
#include <map>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void							checkFileCanBeOpened(std::ifstream& file);
		void							storeDatabase(char* infilePath);
		float							findBtcRate(std::string date);
		int								checkDateValidity(std::string date);
		void							printBtcValue(char* infilePath);
		std::map<std::string, float>	getExchangeRateMap();
		void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);

	private:
		std::map<std::string, float>	_btcExchangeRate;
};

void	printExchangeRate(const std::pair<std::string, float>& exchangeRate);

#endif