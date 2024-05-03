/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactMethods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:34:23 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:11:06 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Sets all of contact's attributes.
 */
void	Contact::set(void) {
	this->_setFirstName();
	this->_setLastName();
	this->_setNickname();
	this->_setPhoneNumber();
	this->_setDarkestSecret();
}

/**
 * Prints all of the contact's information.
 *
 * #### Parameters:
 * `index`─ index of the contact to be printed
 */
void	Contact::print(int index) {

	int	size = _getSize() + 43;

	println("" << WHT);
	println("       ╭" << _configure("─", size, GUARD) << "╮");
	println("       │" << _configure("CONTACT #" + std::string(1, index + 1 + '0'), size, HEADER)	<< "│");
	println("       ├" << _configure("─", size, GUARD) << "┤");
	println("       │" << _configure(" First name: " + this->_firstName, size, FIELD) << "│");
	println("       │" << _configure(" Last name: " + this->_lastName, size, FIELD) << "│");
	println("       │" << _configure(" Nickname: " + this->_nickname, size, FIELD) << "│");
	println("       │" << _configure(" Phone number: " + this->_phoneNumber, size, FIELD) << "│");
	println("       │" << _configure(" Darkest secret: " + this->_darkestSecret, size, FIELD) << "│");
	println("       ╰" << _configure("─", size, GUARD) << "╯");
	println("" << DFL);
}

/**
 * Checks if a contact is valid.
 *
 * #### Returns:
 * bool
 */
bool	Contact::isValid(void) {
	if (this->_firstName.empty())
		return (false);
	return (true);
}
