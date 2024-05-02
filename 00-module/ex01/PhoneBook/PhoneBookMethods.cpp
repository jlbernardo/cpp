/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookMethods.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:14:40 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 02:07:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "catalog.hpp"

void	PhoneBook::add(void) {

	static int i = 0;

	i %= MAX_FRENS;
	this->_friends[i].set();
	i++;
}

void	PhoneBook::search(void) {
	if (!this->_friends[0].is_valid()) {
		error(EMPTY_CNT);
		return ;
	}
	std::cout << std::endl << WHT;
	std::cout << "       ╭──────────┬──────────┬──────────┬──────────╮" << std::endl;
	std::cout << "       │  INDEX   │   NAME   │ SURNAME  │ NICKNAME │" << std::endl;
	std::cout << "       ├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	PhoneBook::_preview();
	std::cout << "       ╰──────────┴──────────┴──────────┴──────────╯" << std::endl;
	std::cout << std::endl << DFL;
	PhoneBook::_select_contact();
}

void	PhoneBook::_select_contact(void) {

	int			index;
	std::string	input;

	while (true) {
		prompt(input, "SEARCH");
		index = std::atoi(input.c_str()) - 1;
		if (index >= 0 && index < 8 && this->_friends[index].is_valid()) {
			this->_friends[index].print(index);
			return ;
		}
		else if (input == "BACK") {
			println("");
			return ;
		}
		else if (input == "EXIT") {
			goodbye();
			exit(EXIT_SUCCESS);
		}
		else {
			error(INDEX_OUT);
		}
	}
}
