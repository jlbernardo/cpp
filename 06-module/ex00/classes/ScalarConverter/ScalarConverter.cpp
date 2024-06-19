/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:47:33 by julberna          #+#    #+#             */
/*   Updated: 2024/06/18 21:41:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string literal) {

	println("");

	if (!validInput(literal)) {
		printError();
		return ;
	}

	switch (getType(literal)) {
		case CHAR:
			printChar(literal);
			break ;
		case INT:
			printInt(literal);
			break ;
		case FLOAT:
			printFloat(literal);
			break ;
		case DOUBLE:
			printDouble(literal);
			break ;
		default:
			printError();
			break ;
	}
}

void	printChar(std::string literal) {
	char	c = *literal.begin();

	std::cout << CYN << "                                        char: " << WHT << std::flush;
	if (!std::isprint(c)) {
		println("non displayable");
	}
	else {
		println("\'" << c << "\'");
	}

	println(CYN << "                                         int: " << WHT << static_cast<int>(c));
	println(CYN << "                                       float: " << WHT << static_cast<float>(c) << ".0f");
	println(CYN << "                                      double: " << WHT << static_cast<double>(c) << ".0");
}

void	printInt(std::string literal) {
	double		i = std::atoi(literal.c_str());

	std::cout << CYN << "                                        char: " << WHT << std::flush;
	if (i < 0 || i > 127) {
		println("impossible");
	}
	else if (!std::isprint(i)) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(i) << "\'");
	}

	println(CYN << "                                         int: " << WHT << static_cast<int>(i));
	println(CYN << "                                       float: " << WHT << static_cast<float>(i) << ".0f");
	println(CYN << "                                      double: " << WHT << static_cast<double>(i) << ".0");
}

void	printFloat(std::string literal) {
	double		f = std::strtof(literal.c_str(), NULL);
	std::string	temp = literal;

	for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
		*it = (char)std::tolower(*it);

	std::cout << CYN << "                                        char: " << WHT << std::flush;
	if (temp == "-inff" || temp == "+inff" || temp == "nanf") {
		println("impossible");
	}
	else if (!std::isprint(static_cast<int>(f))) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(f) << "\'");
	}

	std::cout << CYN << "                                         int: " << WHT << std::flush;
	if (temp == "-inff" || temp == "+inff" || temp == "nanf") {
		println("impossible");
	}
	else {
		println("\'" << static_cast<char>(f) << "\'");
	}

	println(CYN << "                                       float: " << WHT << static_cast<float>(f) << "f");
	println(CYN << "                                      double: " << WHT << static_cast<double>(f));
}

void	printDouble(std::string literal) {
	double		d = std::strtod(literal.c_str(), NULL);
	std::string	temp = literal;

	for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
		*it = (char)std::tolower(*it);

	std::cout << CYN << "                                        char: " << WHT << std::flush;
	if (temp == "-inf" || temp == "+inf" || temp == "nan") {
		println("impossible");
	}
	else if (!std::isprint(static_cast<int>(d))) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(d) << "\'");
	}

	std::cout << CYN << "                                         int: " << WHT << std::flush;
	if (temp == "-inf" || temp == "+inf" || temp == "nan") {
		println("impossible");
	}
	else {
		println(static_cast<int>(d));
	}


	println(CYN << "                                       float: " << WHT << static_cast<float>(d) << "f");
	println(CYN << "                                      double: " << WHT << static_cast<double>(d));
}

void	printError(void) {
	println(CYN << "                                        char: " << RED << "error");
	println(CYN << "                                         int: " << RED << "error");
	println(CYN << "                                       float: " << RED << "error");
	println(CYN << "                                      double: " << RED << "error");

}
