/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:47:54 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 21:12:47 by julberna         ###   ########.fr       */
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
# include "PhoneBook.hpp"


// ************************************************************************** //
//                           Main Program Functions                           //
// ************************************************************************** //

/**
 * Displays a goodbye message to the user. ( ｡◕‿‿◕｡)
 */
void	goodbye(void);

/**
 * Displays an error message to the user.
 *
 * #### Parameters:
 * `EMPTY_CNT`─ No contacts to be shown when trying to 'SEARCH'.
 * `WRONG_CMD`─ Command input not recognized.
 * `INDEX_OUT`─ Index out of bounds or wrong when trying to show contact info.
 */
void	error(int flag);

/**
 * Prompts the user for an action to be taken.
 *
 * #### Parameters:
 * `input`─ Retrieves and stores user's input.
 * `msg`─ Indicates what message should be displayed
 *		  for the user before prompting for an answer.
 */
void	prompt(std::string &input, std::string msg);

#endif
