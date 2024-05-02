/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:15:30 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 14:50:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once //includes this header once
#ifndef CONTACT_HPP
# define CONTACT_HPP


// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include <cstring>


// ************************************************************************** //
//                              Readabily Macros                              //
// ************************************************************************** //

# define FIELD		1
# define GUARD		2
# define HEADER		3
# define println(x) std::cout << x << std::endl;


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

class Contact {

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	void		_set_nickname(void);
	void		_set_last_name(void);
	void		_set_first_name(void);
	void		_set_phone_number(void);
	void		_set_darkest_secret(void);

	int			_get_size(void);
	std::string	_configure(std::string field, std::basic_string<char>::size_type size, int flag);

public:
	void		set(void);
	bool		is_valid(void);
	void		print(int index);

	std::string	get_nickname();
	std::string	get_last_name();
	std::string	get_first_name();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
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
