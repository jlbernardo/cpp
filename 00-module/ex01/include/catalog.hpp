/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:47:54 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 15:20:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once //includes this header once
#ifndef CATALOG_HPP
# define CATALOG_HPP


// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <cstring>
# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"


// ************************************************************************** //
//                              Readabily Macros                              //
// ************************************************************************** //

# define EMPTY_CNT	1
# define WRONG_CMD	2
# define INDEX_OUT	3


// ************************************************************************** //
//                           Main Program Functions                           //
// ************************************************************************** //

void			goodbye(void);
void			error(int flag);
void			prompt(std::string &input, std::string msg);

#endif
