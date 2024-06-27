/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.print.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:18:34 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 13:40:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

void	ScalarConverter::printChar(std::string literal) {
	char	c = *literal.begin();

	std::cout << YLW << SPACE << "  char: " << WHT << std::flush;
	if (!std::isprint(c)) {
		println("non displayable");
	}
	else {
		println("\'" << c << "\'");
	}

	println(CYN << SPACE << "   int: " << WHT << static_cast<int>(c));
	println(CYN << SPACE << " float: " << WHT << static_cast<float>(c) << ".0f");
	println(CYN << SPACE << "double: " << WHT << static_cast<double>(c) << ".0");
}

void	ScalarConverter::printInt(std::string literal) {
	int		i = std::atoi(literal.c_str());

	std::cout << CYN << SPACE << "  char: " << WHT << std::flush;
	if (i < 0 || i > 127) {
		println("impossible");
	}
	else if (!std::isprint(i)) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(i) << "\'");
	}

	println(YLW << SPACE << "   int: " << WHT << static_cast<int>(i));
	println(CYN << SPACE << " float: " << WHT << static_cast<float>(i) << ".0f");
	println(CYN << SPACE << "double: " << WHT << static_cast<double>(i) << ".0");
}

void	ScalarConverter::printFloat(std::string literal) {
	float		f = std::strtof(literal.c_str(), NULL);
	std::string	temp(literal);
	std::string	zero;

	for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
		*it = (char)std::tolower(*it);

	std::cout << CYN << SPACE << "  char: " << WHT << std::flush;
	if (temp == "inff" || temp == "-inff" || temp == "+inff" || temp == "nanf" ||
		f > 127 || f < 0) {
		println("impossible");
	}
	else if (!std::isprint(static_cast<int>(f))) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(f) << "\'");
	}

	std::cout << CYN << SPACE << "   int: " << WHT << std::flush;
	if (temp == "inff" || temp == "-inff" || temp == "+inff" || temp == "nanf" ||
		static_cast<float>(f) >= std::numeric_limits<int>::max() ||
		static_cast<float>(f) <= std::numeric_limits<int>::min()){
		println("impossible");
	}
	else {
		println(static_cast<int>(f));
	}

	if (literal.find(".0") != std::string::npos)
		zero = ".0";

	println(YLW << SPACE << " float: " << WHT << static_cast<float>(f) << zero << "f");
	println(CYN << SPACE << "double: " << WHT << static_cast<double>(f) << zero);
}

void	ScalarConverter::printDouble(std::string literal) {
	double		d = std::strtod(literal.c_str(), NULL);
	std::string	temp(literal);
	std::string	zero;

	for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
		*it = (char)std::tolower(*it);

	std::cout << CYN << SPACE << "  char: " << WHT << std::flush;
	if (temp == "inf" || temp == "-inf" || temp == "+inf" || temp == "nan" ||
		d > 127 || d < 0) {
		println("impossible");
	}
	else if (!std::isprint(static_cast<int>(d))) {
		println("non displayable");
	}
	else {
		println("\'" << static_cast<char>(d) << "\'");
	}

	std::cout << CYN << SPACE << "   int: " << WHT << std::flush;
	if (temp == "inf" || temp == "-inf" || temp == "+inf" || temp == "nan" ||
		d >= static_cast<double>(std::numeric_limits<int>::max()) ||
		d <= static_cast<double>(std::numeric_limits<int>::min())){
		println("impossible");
	}
	else {
		println(static_cast<int>(d));
	}

	if (literal.find(".0") != std::string::npos)
		zero = ".0";

	println(CYN << SPACE << " float: " << WHT << static_cast<float>(d) << zero << "f");
	println(YLW << SPACE << "double: " << WHT << static_cast<double>(d) << zero);
}

void	ScalarConverter::printError() {
	println(CYN << SPACE << "  char: " << RED << "invalid input");
	println(CYN << SPACE << "   int: " << RED << "invalid input");
	println(CYN << SPACE << " float: " << RED << "invalid input");
	println(CYN << SPACE << "double: " << RED << "invalid input");

}
