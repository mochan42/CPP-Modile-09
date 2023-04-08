/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:47 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/08 17:06:55 by mochan           ###   ########.fr       */
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
		void							storeDatabase(const std::string& infilePath);
		float							findBtcRate(std::string date);
		void							printBtcValue(const std::string& infilePath);
		std::map<std::string, float>	getInputMap();
		void    						setInput(const std::pair<std::string, float>& setInput);
		std::map<std::string, float>	getExchangeRateMap();
		void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);

	private:
		std::map<std::string, float>	_btcExchangeRate;
		std::map<std::string, float>	_input;
};

void	printExchangeRate(const std::pair<std::string, float>& exchangeRate);

#endif