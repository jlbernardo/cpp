/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:47:52 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 14:22:54 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLORS_HPP
# define COLORS_HPP

# include <cstdlib>

/**
 * Default color.
 */
# define DFL	"\033[0m"

/**
 * Red bold color.
 */
# define RED	"\033[31;1m"

/**
 * Green bold color.
 */
# define GRN	"\033[32;1m"

/**
 * Yellow bold color.
 */
# define YLW	"\033[33;1m"

/**
 * Blue bold color.
 */
# define BLU	"\033[34;1m"

/**
 * Purple bold color.
 */
# define PRP	"\033[35;1m"

/**
 * Cyan bold color.
 */
# define CYN	"\033[36;1m"

/**
 * White bold color.
 */
# define WHT	"\033[37;1m"

/**
 * Inserts content into the std::cout and adds a new line at the end.
 */
# define println(x) std::cout << x << std::endl;

/**
 * Inserts error message into the std::cerr and adds a new line at the end.
 */
# define errorln(x) std::cerr << RED << x << DFL << std::endl;


#endif
