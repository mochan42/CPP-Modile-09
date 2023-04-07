/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:47 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 14:33:32 by mochan           ###   ########.fr       */
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

		void								storeInput(const std::string& infilePath);
		void    							storeDatabase(const std::string& infilePath);
		std::map<std::string, int>			getInputMap();
		void    							setInput(const std::pair<std::string, int>& setInput);
		std::map<std::string, int>			getExchangeRateMap();
		void    							setExchangeRate(const std::pair<std::string, int>& exchangeRate);

	private:
		std::map<std::string, int>			_btcExchangeRate;
		std::map<std::string, int>			_input;
};

void	printExchangeRate(const std::pair<std::string, int>& exchangeRate);

#endif