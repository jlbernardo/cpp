/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.trade.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:44:10 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 04:36:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void			BitcoinExchange::loadCSV(void) {
	std::string	date;
	std::string	rate;
	std::string	dataString;

	if (!this->_csv.good())
		return ;

	std::getline(this->_csv, dataString);
	std::stringstream	dataStream(dataString);

	if (std::isdigit(*dataString.begin())) {
		while (std::getline(dataStream, dataString, ',')) {
			if (date.empty())
				date = dataString;
			else
				rate = dataString;
		}
		this->_data.insert(std::make_pair(date, std::strtof(rate.c_str(), 0)));
	}
	loadCSV();
}

void			BitcoinExchange::analyzeInput(void) {
	std::string	inputString;

	if (!this->_input.good())
		return ;

	std::getline(this->_input,inputString);
	std::stringstream	inputStream(inputString);

	if (std::isdigit(*inputString.begin()) && formatIsValid(inputString)) {
		while (std::getline(inputStream, inputString, ' ')) {
			if (inputString == "|")
				continue ;
			if (this->_trade.userDate.empty())
				this->_trade.userDate = inputString;
			else
				this->_trade.userValue = std::strtof(inputString.c_str(), 0);
		}
		if (valueIsValid() && dateIsValid())
			calculateExchange();
	}

	this->_trade.userDate.clear();
	analyzeInput();
}

void			BitcoinExchange::calculateExchange(void) {

	mapIter	search = this->_data.find(this->_trade.userDate);
	if (search == this->_data.end())
		search = --this->_data.lower_bound(this->_trade.userDate);

	try {
		if (search == this->_data.end())
			throw std::out_of_range("no bitcoin data on this date!");
		this->_trade.rateDate = search->first;
		this->_trade.rateValue = search->second;
		this->_trade.tradedValue = this->_trade.userValue * this->_trade.rateValue;
		printExchange();
	}
	catch (std::out_of_range &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << this->_trade.userDate);
		errorln("          Expect: " << "dates from " << this->_data.begin()->first << " onwards");
	}

}

void			BitcoinExchange::printExchange(void) {

	std::cout << std::fixed << std::setprecision(2);
	println("");

	println(WHT << "            Date: " << DFL << BLD
				<< this->_trade.userDate);

	println(WHT << "   Exchange rate:" << DFL << BLD << " $"
				<< this->_trade.rateValue << "/btc on " << this->_trade.rateDate);

	println(WHT << "         Bitcoin:" << DFL << BLD << " ₿ "
				<< this->_trade.userValue);

	println(WHT << " Converted value:" << GRN << " $ "
				<< this->_trade.tradedValue);
}
