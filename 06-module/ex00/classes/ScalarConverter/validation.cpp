/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:51:03 by julberna          #+#    #+#             */
/*   Updated: 2024/06/18 19:39:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	validInput(std::string literal) {

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
		*it = (char)std::tolower(*it);

	if (literal.length() == 1 && !std::isalnum(*literal.begin()))
		return (false);

	if (literal.length() == 1 && std::isalnum(*literal.begin()))
		return (true);

	if (literal == "nan" || literal == "nanf" || literal == "-inf" ||
		literal == "+inf" || literal == "-inff" || literal == "+inff")
		return (true);

	if (validFloat(literal))
		return (true);

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++) {
		if (!std::isdigit(*it) && *literal.begin() != '-'
			&& *literal.begin() != '+' && *it != '.')
			return (false);
	}

	if (std::atoll(literal.c_str()) > std::numeric_limits<double>::max() ||
		std::atoll(literal.c_str()) < std::numeric_limits<double>::min())
		return (false);

	return (true);
}

bool	validFloat(std::string literal) {

	int	dot = 0;

	if (*literal.end() != 'f')
		return (false);

	for (std::string::iterator it = literal.begin(); it != literal.end() - 1; it++) {
		if (!std::isdigit(*it) && *it != '.' && *it != '-' && *it != '+')
			return (false);
		if (*it == '.')
			dot++;
	}

	if (dot > 1)
		return (false);

	if (std::isdigit(*literal.end() - 1))
		return (true);

	return (false);
}

int	getType(std::string literal) {

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
		*it = (char)std::tolower(*it);

	if (literal.length() == 1 && std::isalpha(*literal.begin()))
		return (CHAR);

	if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (FLOAT);

	if (literal == "inf" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return (DOUBLE);

	if ((*literal.end() == 'f' && literal.length() > 1))
		return (FLOAT);

	if (literal.find('.') != std::string::npos && literal.length() > 1)
		return (DOUBLE);

	return (INT);
}
