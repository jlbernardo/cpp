/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactGetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:28:53 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 20:59:06 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Returns first name attribute.
 */
std::string&	Contact::getFirstName(void) {
	return (this->_firstName);
}

/**
 * Returns last name attribute.
 */
std::string&	Contact::getLastName(void) {
	return (this->_lastName);
}

/**
 * Returns nickname attribute.
 */
std::string&	Contact::getNickname(void) {
	return (this->_nickname);
}

/**
 * Returns phone number attribute.
 */
std::string&	Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

/**
 * Returns darkest secret attribute.
 */
std::string&	Contact::getDarkestSecret(void) {
	return (this->_darkestSecret);
}

// Convention:
// They return a reference to the attribute, instead of a copy of it.
