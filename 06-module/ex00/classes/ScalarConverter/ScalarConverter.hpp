/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:43:57 by julberna          #+#    #+#             */
/*   Updated: 2024/06/19 15:46:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <limits>
# include <string>
# include "general.hpp"

# define CHAR			0
# define INT			1
# define FLOAT			2
# define DOUBLE			3
# define TOTAL_TYPES	4

# define SPACE			"                                      "

/**
 * #### Scalar Converter class
 *
 * Converts a string literal to char, int, float and double
 */
class ScalarConverter {
private:
					/**
					 * @brief Constructs a new Scalar Converter object.
					 */
					ScalarConverter(void);

					/**
					 * @brief Destroys the Scalar Converter object.
					 */
					~ScalarConverter(void);

					/**
					 * @brief Copy Constructor.
					 * @param copy The object to copy from.
					 */
					ScalarConverter(const ScalarConverter &copy);

					/**
					 * @brief Assignment operator.
					 * @param rhs The object to copy from.
					 * @return ScalarConverter& - A reference to the object.
					 */
	ScalarConverter	&operator=(const ScalarConverter &rhs);

					/**
					 * @brief Gets the type of the literal;
					 * @param literal The string literal to check.
					 * @return int - A macro corresponding to the type.
					 */
	static int		getType(std::string literal);

					/**
					 * @brief Prints all types for a char literal.
					 * @param literal The string literal to convert.
					 */
	static void		printChar(std::string literal);

					/**
					 * @brief Prints all types for an int literal.
					 * @param literal The string literal to convert.
					 */
	static void		printFloat(std::string literal);

					/**
					 * @brief Prints all types for a float literal.
					 * @param literal The string literal to convert.
					 */
	static void		printDouble(std::string literal);

					/**
					 * @brief Checks if the literal is a valid float.
					 * @param literal The string literal to check.
					 */
	static bool		validFloat(std::string literal);

					/**
					 * @brief Prints all types for an int literal.
					 * @param literal The string literal to convert.
					 */
	static void		printInt(std::string literal);

					/**
					 * @brief Checks if the input is valid.
					 * @param literal The string literal to check.
					 */
	static bool		validInput(std::string);

					/**
					 * @brief Prints an error message.
					 */
	static void		printError(void);


public:
					/**
					 * @brief Converts the string literal to char, int, float and double.
					 * @param literal The string literal to convert.
					 */
	static void		convert(std::string literal);
};

#endif
