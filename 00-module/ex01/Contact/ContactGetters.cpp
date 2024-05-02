/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactGetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:28:53 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 01:53:55 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::get_first_name(void) {
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) {
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) {
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) {
	return (this->_darkest_secret);
}
