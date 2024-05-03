/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:35:55 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:09:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Configures the field to be printed. It can be a field, a guard or a header.
 *
 * #### Parameters:
 * `field`─ string to be configured and returned
 * `size`─ size of the desidera returned string
 * `flag`─ flag to determine the type of configuration
 *
 * #### Returns:
 * std::string
 */
std::string	Contact::_configure(std::string field, std::size_t size, int flag) {

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

/**
 * Gets size of longest contact field..
 */
int	Contact::_getSize(void) {

	std::string	longest;

	longest = " First name: " + this->_firstName;
	if (longest.length() < (" Last name: " + this->_lastName).length() + 1)
		longest = " Last name: " + this->_lastName;
	if (longest.length() < (" Nickname: " + this->_nickname).length() + 1)
		longest = " Nickname: " + this->_nickname;
	if (longest.length() < (" Phone number: " + this->_phoneNumber).length() + 1)
		longest = " Phone: " + this->_phoneNumber;
	if (longest.length() < (" Darkest secret: " + this->_darkestSecret).length() + 1)
		longest = " Secret: " + this->_darkestSecret;

	return (longest.length() + 1);
}
