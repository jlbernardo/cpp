/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:18:15 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 21:30:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>

int	main(void) {

	std::string	string		= "HI THIS IS BRAIN";
	std::string	*stringPTR	= &string;
	std::string	&stringREF	= string;

	std::cout << GRN << &string		<< WHT << " is the memory address of string." << std::endl;
	std::cout << GRN << &stringPTR	<< WHT << " is the memory address of stringPTR." << std::endl;
	std::cout << GRN << &stringREF	<< WHT << " is the memory address of stringREF.\n" << std::endl;

	std::cout << '"' << BLU << string		<< WHT << "\" is the value of string." << std::endl;
	std::cout << '"' << BLU << *stringPTR	<< WHT << "\" is the value of stringPTR." << std::endl;
	std::cout << '"' << BLU << stringREF	<< WHT << "\" is the value of stringREF." << std::endl;
}
