/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:15:19 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 14:51:05 by julberna         ###   ########.fr       */
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
//                              Readabily Macros                              //
// ************************************************************************** //

# define EMPTY_CNT	1
# define WRONG_CMD	2
# define INDEX_OUT	3
# define MAX_FRENS	8
# define FIRST_FREN	0
# define println(x) std::cout << x << std::endl;



// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

class PhoneBook {

private:
	Contact		_friends[MAX_FRENS];

	void		_preview(void);
	void		_select_contact(void);
	std::string	_truncate(std::string field);

public:
	void		add(void);
	void		search(void);
};



// ************************************************************************** //
//                              ANSI Color Codes                              //
// ************************************************************************** //

# define DFL	"\033[0m"
# define RED	"\033[31;1m"
# define GRN	"\033[32;1m"
# define YLW	"\033[33;1m"
# define BLU	"\033[34;1m"
# define PRP	"\033[35;1m"
# define CYN	"\033[36;1m"
# define WHT	"\033[37;1m"

#endif
