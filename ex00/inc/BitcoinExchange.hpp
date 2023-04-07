/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:47 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/07 07:59:33 by moninechan       ###   ########.fr       */
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

class   BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void    storeDatabase(const std::string& inputFilePath);
        set     btcExchangeRate();

    private:
        std::map<std::string, int>  btcExchangeRate;
};

#endif