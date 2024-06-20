/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.base.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:47:33 by julberna          #+#    #+#             */
/*   Updated: 2024/06/19 18:32:32 by julberna         ###   ########.fr       */
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

	void	(*print[TOTAL_TYPES])(std::string) = {
			&ScalarConverter::printChar,
			&ScalarConverter::printInt,
			&ScalarConverter::printFloat,
			&ScalarConverter::printDouble
	};

	// println(getType(literal));

	print[getType(literal)](literal);
}
