/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:38:07 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/10 09:38:14 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class RPN
{
	private:
		std::stack<int>		_A;
		std::stack<char>	_B;
		std::string			_input;
		RPN(const RPN& obj);
		RPN& 	operator=(const RPN& rhs);
		int		inputCheck(const std::string input);
		int		operate();
		void	printResult();
	public:
		RPN();
		~RPN();
		int		calculate(const std::string input);
};

#endif