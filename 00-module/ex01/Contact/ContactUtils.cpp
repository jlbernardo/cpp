/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:35:55 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 01:53:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::_configure(std::string field, std::basic_string<char>::size_type size, int flag) {

	size -= 43;

	if (size < 43)
		size = 43;

	switch (flag) {
		case FIELD:
			while (field.length() < size) {
				field.insert(field.length(), " ");
			}
			break ;

		case GUARD:
			while (field.length() < size * 4 - size) {
				field.insert(field.length(), "─");
			}
			break ;

		case HEADER:
			while (field.length() < size) {
				field.insert(0, " ");
				if (field.length() < size)
					field.insert(field.length(), " ");
			}
			break ;
	}

	return (field);
}

int	Contact::_get_size(void) {

	std::string	longest;

	longest = " First name: " + this->_first_name;
	if (longest.length() < (" Last name: " + this->_last_name).length() + 1)
		longest = " Last name: " + this->_last_name;
	if (longest.length() < (" Nickname: " + this->_nickname).length() + 1)
		longest = " Nickname: " + this->_nickname;
	if (longest.length() < (" Phone number: " + this->_phone_number).length() + 1)
		longest = " Phone: " + this->_phone_number;
	if (longest.length() < (" Darkest secret: " + this->_darkest_secret).length() + 1)
		longest = " Secret: " + this->_darkest_secret;

	return (longest.length() + 1);
}
