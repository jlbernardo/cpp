/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:08:22 by julberna          #+#    #+#             */
/*   Updated: 2024/06/19 15:48:38 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void) {

	std::string	input;

	println("");
	ScalarConverter::convert("0");

	while (true) {
		println("");

		println(WHT	<< "                     Enter a literal to convert or press '"
					<< RED << "CTRL + D" << WHT << "' to exit.");
		println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
		std::cout << WHT << "               ╰─➤ " << DFL;

		std::getline(std::cin, input);
		println("\033c");

		if (std::cin.eof() == 1)
			break ;

		ScalarConverter::convert(input);
	}
}
