/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.canonical.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:34 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 02:46:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _csv("data.csv", std::ifstream::in) {

	if (!this->_csv.good())
		throw std::ios_base::failure("failed to open data file");

	this->loadCSV();
	this->_trade.userDate.clear();
}

BitcoinExchange::BitcoinExchange(char *input) : _csv("data.csv", std::ifstream::in),
	_input(input, std::ifstream::in) {

	if (!this->_input.good())
		throw std::ios_base::failure("failed to open input file");

	if (!this->_csv.good())
		throw std::ios_base::failure("failed to open data file");

	this->loadCSV();
	this->_trade.userDate.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {
	this->_csv.close();
	this->_input.close();
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	(void)rhs;
	return (*this);
}
