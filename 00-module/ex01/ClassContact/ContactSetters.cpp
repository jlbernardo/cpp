/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactSetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:38:34 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:26:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Sets nickname attribute.
 */
void Contact::_setFirstName(void)
{
	this->_firstName.clear();
	while (this->_firstName.empty())
	{
		println(WHT << "\n┌ Input contact's first name:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_firstName);
	}
}

/**
 * Sets last name attribute.
 */
void Contact::_setLastName(void)
{
	this->_lastName.clear();
	while (this->_lastName.empty())
	{
		println(WHT << "\n┌ Input contact's last name:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_lastName);
	}
}

/**
 * Sets nickname attribute.
 */
void Contact::_setNickname(void)
{
	this->_nickname.clear();
	while (this->_nickname.empty())
	{
		println(WHT << "\n┌ Input contact's nickname:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_nickname);
	}
}

/**
 * Sets phone number attribute.
 */
void Contact::_setPhoneNumber(void)
{
	this->_phoneNumber.clear();
	while (this->_phoneNumber.empty())
	{
		println(WHT << "\n┌ Input contact's phone number:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_phoneNumber);
	}
}

/**
 * Sets darkest secret attribute.
 */
void Contact::_setDarkestSecret(void)
{
	this->_darkestSecret.clear();
	while (this->_darkestSecret.empty())
	{
		println(WHT << "\n┌ Input contact's darkest secret:");
		std::cout << "└─➤ " << DFL;
		std::getline(std::cin, this->_darkestSecret);
		std::cout << std::endl;
	}
}
