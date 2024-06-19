/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:43:57 by julberna          #+#    #+#             */
/*   Updated: 2024/06/18 21:36:38 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "general.hpp"
# include <string>

# define CHAR		0
# define INT		1
# define FLOAT		2
# define DOUBLE		3
# define SPECIAL	4

class ScalarConverter {
private:
					ScalarConverter(void);
					~ScalarConverter(void);
					ScalarConverter(const ScalarConverter &copy);
	ScalarConverter	&operator=(const ScalarConverter &rhs);


public:
	static void		convert(std::string literal);
};

int					getType(std::string literal);
bool				validInput(std::string);
void				printChar(std::string literal);
void				printInt(std::string literal);
void				printFloat(std::string literal);
void				printDouble(std::string literal);
bool				validFloat(std::string literal);
void				printError(void);


#endif
