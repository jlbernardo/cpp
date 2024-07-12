/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:34 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 01:24:24 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream					BitcoinExchange::_csv("data.csv", std::ifstream::in);
std::map<std::string, float>	BitcoinExchange::_data;

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {
	_csv.close();
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	(void)rhs;
	return (*this);
}

void			BitcoinExchange::printCSV(void) {
	for (mapIter it = _data.begin(); it != _data.end(); it++)
		println(it->first << ":" << it->second);

	_csv.close();
}

void			BitcoinExchange::loadCSV(void) {
	std::string	key;
	std::string	value;
	std::string	dataString;

	if (!_csv.good())
		return ;

	std::getline(_csv, dataString);
	std::stringstream	dataStream(dataString);

	if (dataString != "date,exchange rate" && std::isdigit(*dataString.begin())) {
		while (std::getline(dataStream, dataString, ',')) {
			if (key.empty())
				key = dataString;
			else
				value = dataString;
		}
		_data.insert(std::make_pair(key, std::strtof(value.c_str(), 0)));
	}
	loadCSV();
}
