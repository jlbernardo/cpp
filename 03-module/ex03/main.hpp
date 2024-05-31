/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/05/30 21:18:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "DiamondTrap.hpp"

void		waitAndClean(void);
void		destructionMessage(void);
void		constructionMessage(void);
void		fight(DiamondTrap &attacker, DiamondTrap &defender);
void		action(DiamondTrap &attacker, DiamondTrap &defender);
void		printScreen(DiamondTrap &attacker, DiamondTrap &defender);
std::string	printHighFive(DiamondTrap &attacker, DiamondTrap &defender);

#endif
