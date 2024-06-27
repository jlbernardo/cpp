/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.validation.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:51:03 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 15:35:25 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::validInput(std::string literal) {

	int	dot = 0;

	//Converts the input to lowercase to make it easier to compare
	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
		*it = (char)std::tolower(*it);

	//If the input is a single character, it is either a char or an int,
	//so it is valid either way
	if (literal.length() == 1 )
		return (true);

	//If the input is one of these, it is valid
	if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "-inf" ||
		literal == "+inf" || literal == "inff" || literal == "-inff" || literal == "+inff")
		return (true);

	//If it passes the float validation, it is valid
	//But if it doesn't and contains an 'f' at the end, it is not valid
	if (validFloat(literal))
		return (true);
	else if (*literal.rbegin() == 'f')
		return (false);

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++) {
		//If the input contains something that is not a digit or a dot,
		//or has a sign that is not in the beginning of the string, it is not valid
		if (!std::isdigit(*it) && *it != '.' && *it != '-' && *it != '+')
			return (false);
		if ((*it == '-' || *it == '+') && it != literal.begin())
			return (false);
		if (*it == '.')
			dot++;
	}

	//If there's more than one dot, it is not a valid number
	if (dot > 1)
		return (false);

	//If the number ends with a dot, it is not valid
	if (*literal.rbegin() == '.')
		return (false);

	//If there's no dot in the number, it is valid
	if (literal.find('.') == std::string::npos)
		return (true);

	//If the number is within the limits of an int, it is valid
	if (std::atol(literal.c_str()) <= static_cast<long int>(std::numeric_limits<int>::max()) ||
		std::atol(literal.c_str()) >= static_cast<long int>(std::numeric_limits<int>::min()))
		return (true);

	//If the number is within the limits of a float, it is valid
	if (std::strtod(literal.c_str(), NULL) <= static_cast<double>(std::numeric_limits<float>::max()) ||
		std::strtod(literal.c_str(), NULL) >= static_cast<double>(std::numeric_limits<float>::min()))
		return (true);

	//If the number is within the limits of a double, it is valid
	if (std::strtold(literal.c_str(), NULL) <= static_cast<long double>(std::numeric_limits<double>::max()) ||
		std::strtold(literal.c_str(), NULL) >= static_cast<long double>(std::numeric_limits<double>::min()))
		return (true);

	//If all the checks above fail, the number is not valid
	return (false);
}

bool	ScalarConverter::validFloat(std::string literal) {

	int	dot = 0;

	//If there's no 'f' at the end of the string, it's not a float
	if (*literal.rbegin() != 'f' || literal.find('.') == std::string::npos)
		return (false);

	for (std::string::iterator it = literal.begin(); it != literal.end() - 1; it++) {
		//If the character is not a digit, a dot, a minus or a plus, it's not a valid number
		if (!std::isdigit(*it) && *it != '.' &&
			((*it == '-' || *it == '+') && it != literal.begin()))
			return (false);
		if (*it == '.')
			dot++;
	}

	//If there's more than one dot, it's not a valid number
	if (dot > 1)
		return (false);

	//It necessarily needs to have a number preceding the 'f'
	if (std::isdigit(*(literal.rbegin() + 1)))
		return (true);

	//If the above condition is not true, then it is not a valid number
	return (false);
}

int	ScalarConverter::getType(std::string literal) {

	//Converts the input to lowercase to make it easier to compare
	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
		*it = (char)std::tolower(*it);

	//Ift the input is a single character and alpha, it is a char
	if (literal.length() == 1 && !std::isdigit(*literal.begin()))
		return (CHAR);

	//If the input matches one of these, it is a float
	if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (FLOAT);

	//If the input matches one of these, it is a double
	if (literal == "inf" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return (DOUBLE);

	//If there's an 'f' at the end and didn't count as char, it is a float
	if (validFloat(literal))
		return (FLOAT);

	//If there is a dot in the string and it is not a single character, it is a double
	if (literal.find('.') != std::string::npos && literal.length() > 1)
		return (DOUBLE);

	//If there's no dot in the string and the number is within the limits of an int, it is an int
	if (literal.find('.') == std::string::npos &&
		std::atol(literal.c_str()) <= static_cast<long int>(std::numeric_limits<int>::max()) &&
		std::atol(literal.c_str()) >= static_cast<long int>(std::numeric_limits<int>::min()))
		return (INT);

	//If the number is smaller than the maximum float, bigger than the minimum negative float and bigger than the minimum positive float, it is a float
	if (std::strtod(literal.c_str(), NULL) <= static_cast<double>(std::numeric_limits<float>::max()) &&
		std::fabs(std::strtod(literal.c_str(), NULL) - static_cast<double>(std::numeric_limits<float>::min())) > 0.0000001 &&
		std::strtod(literal.c_str(), NULL) >= static_cast<double>(-std::numeric_limits<float>::max()))
		return (FLOAT);

	//If all the checks fail, it is probably a double
	return (DOUBLE);
}
