/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:38:37 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:13:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * Prints the preview of the contacts.
 */
void	PhoneBook::_preview(void) {
	for (int i = 0; i < MAX_FRENS; i++) {
		if (this->_friends[i].isValid()) {
			std::cout << "       │";
			std::cout << _truncate("#" + std::string(1, i + 1 + '0')) << "│";
			std::cout << _truncate(this->_friends[i].getFirstName()) << "│";
			std::cout << _truncate(this->_friends[i].getLastName()) << "│";
			std::cout << _truncate(this->_friends[i].getNickname()) << "│";
			println("");
		}
	}
}

/**
 * Truncates a field to 10 characters.
 *
 * #### Parameters:
 * `field`─ field to be truncated
 *
 * #### Returns:
 * std::string
 */
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
