/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 22:03:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "FragTrap.hpp"

void		waitAndClean(void);
void		destructionMessage(void);
void		constructionMessage(void);
void		fight(FragTrap &attacker, FragTrap &defender);
void		action(FragTrap &attacker, FragTrap &defender);
void		printScreen(FragTrap &attacker, FragTrap &defender);
std::string	printHighFive(FragTrap &attacker, FragTrap &defender);

#endif
