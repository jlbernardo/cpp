/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:15:30 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:22:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once //includes this header once
#ifndef CONTACT_HPP
# define CONTACT_HPP


// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <cstdlib>
# include <iostream>
# include <cstring>
# include "colors.hpp"
# include "macros.hpp"


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * Stores one contact's information.
 * #
 * #### Attributes:
 * first name, last name, nickname, phone number and darkest secret.
 * #### Methods:
 * set(), print() and isValid(), as well as getters for each attribute.
 */
class Contact {

private:
	std::string		_firstName;					// First name attribute
	std::string		_lastName;					// Last name attribute
	std::string		_nickname;					// Nickname attribute
	std::string		_phoneNumber;				// Phone number attribute
	std::string		_darkestSecret;				// Darkest secret attribute

	void			_setNickname(void);
	void			_setLastName(void);
	void			_setFirstName(void);
	void			_setPhoneNumber(void);
	void			_setDarkestSecret(void);

	int				_getSize(void);
	std::string		_configure(std::string field, std::size_t size, int flag);

public:
	void			set(void);
	bool			isValid(void);
	void			print(int index);

	std::string&	getNickname();
	std::string&	getLastName();
	std::string&	getFirstName();
	std::string&	getPhoneNumber();
	std::string&	getDarkestSecret();
};

#endif
