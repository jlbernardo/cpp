/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:47:54 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 01:52:55 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATALOG_HPP
# define CATALOG_HPP

/* Libraries */
# include <cstring>
# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

/* Readability macros */
# define EMPTY_CNT	1
# define WRONG_CMD	2
# define INDEX_OUT	3

/* Main program */
void			goodbye(void);
void			error(int flag);
void			prompt(std::string &input, std::string msg);

#endif
