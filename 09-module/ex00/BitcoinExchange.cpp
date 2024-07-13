/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:34 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 02:32:45 by julberna         ###   ########.fr       */
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

bool			BitcoinExchange::dateIsValid(void) {

	int					year = -1, month = -1, day = -1;
	time_t				t = time(0);
	struct tm			*curr = localtime(&t);
	struct tm			date = {0, 0, 0, 0, 0, 0, 0, 0, -1, -1, "GMT"};
	std::string			value;
	std::stringstream	ss(this->_trade.userDate);

	try {

		for (std::string::const_iterator it = this->_trade.userDate.begin();
										it != this->_trade.userDate.end(); it++) {
			if (!std::isdigit(*it) && *it != '-')
				throw std::invalid_argument("unexpected character on date!");
		}

		while (std::getline(ss, value, '-')) {
			if (year == -1)
				date.tm_year = year = std::strtol(value.c_str(), 0, 10) - 1900;
			else if (month == -1)
				date.tm_mon = month = std::strtol(value.c_str(), 0, 10) - 1;
			else if (day == -1)
				date.tm_mday = day = std::strtol(value.c_str(), 0, 10);
			else
				throw std::length_error("incorrect date!");
		}
		if (year == -1 || month == -1 || day == -1)
			throw std::invalid_argument("incorrect date!");

		if (year > curr->tm_year || (year == curr->tm_year && month > curr->tm_mon) ||
			(year == curr->tm_year && month == curr->tm_mon && day > curr->tm_mday))
			throw std::range_error("invalid date!");

		if (mktime(&date) == -1 || date.tm_year != year ||
			date.tm_mon != month || date.tm_mday != day)
			throw std::out_of_range("invalid date!");

		return (true);
	}
	catch (std::logic_error &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << this->_trade.userDate);
		errorln("          Expect: " << "'yyyy-mm-dd'");
	}
	catch (std::range_error &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << this->_trade.userDate);
		errorln("          Expect: " << "date not in the future");
	}
	return (false);
}

bool			BitcoinExchange::valueIsValid(void) {

	float	value = this->_trade.userValue;

	if (value >= 0 && value <= 1000)
		return (true);

	std::cerr << std::endl << RED << "           ERROR: ";

	if (value < 0)
		errorln("not a positive number!");

	if (value > 1000)
		errorln("value too large!");

	errorln("           Entry: " << value);
	errorln("          Expect: 0-1000 range");

	return (false);
}

bool			BitcoinExchange::formatIsValid(std::string entry) {

	int					wordCount = 0;
	std::string			word;
	std::stringstream	ss(entry);

	try {
		if (entry.find('|') == std::string::npos)
			throw std::invalid_argument("incorrect entry!");
	}
	catch (std::invalid_argument &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << entry);
		errorln("          Expect: " << "'date | value'");
		return (false);
	}

	if (ss >> word)
		wordCount++;

	try {
		if (std::count(word.begin(), word.end(), '-') != 2)
			throw std::invalid_argument("incorrect date!");
	}
	catch (std::invalid_argument &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << word);
		errorln("          Expect: " << "'yyyy-mm-dd'");
		return (false);
	}

	if (ss >> word) {
		wordCount++;
		if (ss >> word)
			wordCount++;
	}

	try {
		if (wordCount == 3 && (std::count(word.begin(), word.end(), '.') > 1 ||
								std::count(word.begin(), word.end(), '+') > 1 ||
								std::count(word.begin(), word.end(), '-') > 1))
			throw std::invalid_argument("incorrect value!");

		for (std::string::iterator it = word.begin(); it != word.end(); it++) {
			if (!std::isdigit(*it) && *it != '.' && *it != '-' && *it != '+')
				throw std::invalid_argument("unexpected character on value!");
		}
	}
	catch (std::invalid_argument &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << word);
		errorln("          Expect: " << "'42' or '42.2'");
		return (false);
	}

	try {
		while (ss >> word)
			wordCount++;

		if (wordCount > 3)
			throw std::length_error("too many entry values!");

		return (true);
	}
	catch (std::logic_error &e) {
		println("");
		errorln("           ERROR: " << e.what());
		errorln("           Entry: " << entry);
		errorln("          Expect: " << "'date | value'");
		return (false);
	}
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

	println(WHT << "  Original value:" << DFL << BLD << " $"
				<< this->_trade.userValue);

	println(WHT << " Exchanged value:" << GRN << " $"
				<< this->_trade.tradedValue);
}
