/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactMethods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:34:23 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 01:53:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set(void) {
	this->_set_first_name();
	this->_set_last_name();
	this->_set_nickname();
	this->_set_phone_number();
	this->_set_darkest_secret();
}

void	Contact::print(int index) {

	int	size = _get_size() + 43;

	println("" << WHT);
	println("       ╭" << _configure("─", size, GUARD) << "╮");
	println("       │" << _configure("CONTACT #" + std::string(1, index + 1 + '0'), size, HEADER)	<< "│");
	println("       ├" << _configure("─", size, GUARD) << "┤");
	println("       │" << _configure(" First name: " + this->_first_name, size, FIELD) << "│");
	println("       │" << _configure(" Last name: " + this->_last_name, size, FIELD) << "│");
	println("       │" << _configure(" Nickname: " + this->_nickname, size, FIELD) << "│");
	println("       │" << _configure(" Phone number: " + this->_phone_number, size, FIELD) << "│");
	println("       │" << _configure(" Darkest secret: " + this->_darkest_secret, size, FIELD) << "│");
	println("       ╰" << _configure("─", size, GUARD) << "╯");
	println("" << DFL);
}

bool	Contact::is_valid(void) {
	if (this->_first_name.empty())
		return (false);
	return (true);
}
