/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:08:58 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:22:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <fstream>
# include <iostream>
# include "colors.hpp"

bool	validation(int argc, char **argv, std::ifstream &origin);
void	replace(std::ifstream &origin, std::ofstream &result, char **argv);

#endif
