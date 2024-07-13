/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.validation.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:43:53 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 02:46:15 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
