/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:15:19 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:15:05 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once //includes this header once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <cmath>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include "Contact.hpp"

// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //


/**
 * Stores up to 8 contacts.
 * #
 * #### Attributes:
 * An array of 8 contacts.
 * #### Methods:
 * add() and search().
 */
class PhoneBook {

private:
	Contact		_friends[MAX_FRENS];	//Array of 8 contacts

	void		_preview(void);
	void		_selectContact(void);
	std::string	_truncate(std::string field);

public:
	void		add(void);
	void		search(void);
};

#endif
