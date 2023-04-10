/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.CPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:36:22 by moninechan        #+#    #+#             */
/*   Updated: 2023/04/10 09:36:59 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN&	obj)
{
	this->_input = obj._input;
	this->_A = obj._A;
	this->_B = obj._B;
}

RPN& RPN::operator=(const RPN& rhs)
{
	this->_input = rhs._input;
	this->_A = rhs._A;
	this->_B = rhs._B;
	return (*this);
}

// #################### MEMBER FUNCTIONS ############################

int	RPN::calculate(const std::string input)
{
	// std::cout << input << std::endl;
	if (this->inputCheck(input) == -1)
		return (0);
	this->_input = input;
	int i = 0;
	while (this->_input[i])
	{
		if (this->_input[i] >= '0' && this->_input[i] <= '9')
			this->_A.push(((int)this->_input[i] - 48));
		else if (this->_input[i] != ' ')
			this->_B.push(this->_input[i]);
		if (!this->_A.empty() && !this->_B.empty())
			if (this->operate() == -1)
				return (0);
		i++;
	}
	if (!this->_B.empty())
	{
		std::cout << "Error\n";
		return (0);
	}
	this->printResult();
	return (this->_A.top());
}

int	RPN::operate()
{
	if (_A.size() < 2)
	{
		std::cout << "Error\n";
		return (-1);
	}
	int	second_op = (int)this->_A.top();
	this->_A.pop();
	int	first_op = (int)this->_A.top();
	this->_A.pop();
	if (this->_B.top() == '+')
	{
		this->_A.push(first_op + second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '-')
	{
		this->_A.push(first_op - second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '*')
	{
		this->_A.push(first_op * second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '/')
	{
		this->_A.push(first_op / second_op);
		this->_B.pop();
	}
	return (0);
}

void	RPN::printResult()
{
	std::cout << (this->_A.top()) << std::endl;
}

int	RPN::inputCheck(const std::string input)
{
	int	size = input.size();
	for (int i = 0; i < size; i++)
	{
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
		{
			if (i < (size -1) && input[i + 1] != ' ')
			{
				std::cout << "Error\n";
				return (-1);
			}
		}
		else if (input[i] != ' ')
		{
			std::cout << "Error\n";
			return (-1);
		}
	}
	if (input.empty())
	{
		std::cout << "Error\n";
		return (-1);
	}
	int count_a = 0;
	int count_b = 0;
	for (int i = 0; i < size; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			count_a++;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			count_b++;
		if (count_b > count_a && count_a < 2)
		{
			std::cout << "Error\n";
			return (-1);
		}
	}
	if (count_b >= count_a)
	{
		std::cout << "Error\n";
		return (-1);
	}
	return (0);
}