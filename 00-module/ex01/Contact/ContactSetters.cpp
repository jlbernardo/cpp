/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactSetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:38:34 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 00:37:38 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::_set_first_name(void) {
	this->_first_name.clear();
	while (this->_first_name.empty())
	{
		println(WHT << "\n┌ Input contact's first name:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_first_name);
	}
}

void	Contact::_set_last_name(void) {
	this->_last_name.clear();
	while (this->_last_name.empty())
	{
		println(WHT << "\n┌ Input contact's last name:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_last_name);
	}
}

void	Contact::_set_nickname(void) {
	this->_nickname.clear();
	while (this->_nickname.empty())
	{
		println(WHT << "\n┌ Input contact's nickname:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_nickname);
	}
}

void	Contact::_set_phone_number(void) {
	this->_phone_number.clear();
	while (this->_phone_number.empty())
	{
		println(WHT << "\n┌ Input contact's phone number:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_phone_number);
	}
}

void	Contact::_set_darkest_secret(void) {
	this->_darkest_secret.clear();
	while (this->_darkest_secret.empty())
	{
		println(WHT << "\n┌ Input contact's darkest secret:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_darkest_secret);
		std::cout << std::endl;
	}
}
