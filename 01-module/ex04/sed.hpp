/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:08:58 by julberna          #+#    #+#             */
/*   Updated: 2024/05/08 09:59:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <fstream>
# include <iostream>
# include "general.hpp"

/**
 * @brief Function to check if the arguments are valid.
 *
 * @param argc Number of arguments.
 * @param argv Arguments received.
 * @param origin File to read.
 * @return true for valid arguments.
 * @return false for invalid ones.
 */
bool	validation(int argc, char **argv, std::ifstream &origin);

/**
 * @brief Function to replace a string in a file.
 *
 * @param origin File to read.
 * @param result File to write.
 * @param argv Arguments received.
 */
void	replace(std::ifstream &origin, std::ofstream &result, char **argv);

#endif
