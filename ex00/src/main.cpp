/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:45 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/06 21:58:22 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

int main(int ac, char **av)
{
	(void) ac;
	(void) av;

	std::ifstream btcDatabase("data.csv");
    if (!btcDatabase.is_open())
    {
    	std::cout << RED << "Error: data.csv file could not be opened" << D << "\n";
		return (0);
    }
	std::string	line;
	{
		while(getline(btcDatabase, line))
		{
			std::cout << line << "\n";
		}
	}
	return (0);
}