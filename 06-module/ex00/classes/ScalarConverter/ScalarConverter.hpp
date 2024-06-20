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
# define MIN_INT		static_cast<long double>(std::numeric_limits<int>::min())
# define MAX_INT		static_cast<long double>(std::numeric_limits<int>::max())
# define MIN_FLOAT		static_cast<long double>(std::numeric_limits<float>::min())
# define MAX_FLOAT		static_cast<long double>(std::numeric_limits<float>::max())
# define MIN_DOUBLE		static_cast<long double>(std::numeric_limits<double>::min())
# define MAX_DOUBLE		static_cast<long double>(std::numeric_limits<double>::max())

class ScalarConverter {
private:
					ScalarConverter(void);
					~ScalarConverter(void);
					ScalarConverter(const ScalarConverter &copy);
	ScalarConverter	&operator=(const ScalarConverter &rhs);

	static int		getType(std::string literal);
	static void		printChar(std::string literal);
	static void		printFloat(std::string literal);
	static void		printDouble(std::string literal);
	static bool		validFloat(std::string literal);
	static void		printInt(std::string literal);
	static bool		validInput(std::string);
	static void		printError(void);


public:
	static void		convert(std::string literal);
};

#endif
