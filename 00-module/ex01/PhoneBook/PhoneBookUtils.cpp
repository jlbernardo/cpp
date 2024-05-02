/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:38:37 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 01:54:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::_preview(void) {
	for (int i = 0; i < MAX_FRENS; i++) {
		if (this->_friends[i].is_valid()) {
			std::cout << "       │";
			std::cout << _truncate("#" + std::string(1, i + 1 + '0')) << "│";
			std::cout << _truncate(this->_friends[i].get_first_name()) << "│";
			std::cout << _truncate(this->_friends[i].get_last_name()) << "│";
			std::cout << _truncate(this->_friends[i].get_nickname()) << "│";
			println("");
		}
	}
}

std::string	PhoneBook::_truncate(std::string field) {
	while (field.length() < 10) {
		field.insert(0, " ");
	}
	if (field.length() > 10) {
		field.resize(9);
		field.insert(9, ".");
	}
	return (field);
}
