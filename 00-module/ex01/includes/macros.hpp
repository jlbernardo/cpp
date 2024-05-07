/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:49:26 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:33:30 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MACROS_HPP
# define MACROS_HPP

/**
 * No contacts to be shown on phonebook preview.
 * #
 */
# define EMPTY_CNT	1

/**
 * Command not recognized.
 * #
 */
# define WRONG_CMD	2

/**
 * Index choosen is out of bounds or wrong.
 * #
 */
# define INDEX_OUT	3

/**
 * Maximum number of friends supported by the phonebook.
 * #
 */
# define MAX_FRENS	8

/**
 * The OG friend, the first person you thought about and added.
 * #
 */
# define FIRST_FREN	0

/**
 * Contact fields exhibition.
 * #
 */
# define FIELD		1

/**
 * Box drawing separations.
 * #
 */
# define GUARD		2

/**
 * Box header titles.
 * #
 */
# define HEADER		3

#endif
