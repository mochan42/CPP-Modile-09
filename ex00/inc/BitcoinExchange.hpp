/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:47 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 12:47:14 by mochan           ###   ########.fr       */
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

		void    							storeDatabase(const std::string& infilePath);
		std::map<std::string, int>			getExchangeRateMap();
		void    							setExchangeRate(const std::pair<std::string, int>& exchangeRate);

	private:
		std::map<std::string, int>			_btcExchangeRate;
};

void	printExchangeRate(const std::pair<std::string, int>& exchangeRate);

#endif