/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:22:06 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:19:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catalog.hpp"

int	main() {

	std::string	input;
	PhoneBook	phonebook;

	while (true) {
		prompt(input, "BASIC");
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT" || std::cin.eof() == 1)
			break ;
		else
			error(WRONG_CMD);
	}
	goodbye();
}


