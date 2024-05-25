/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 19:01:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "ScavTrap.hpp"

void	waitAndClean(void);
void	destructionMessage(void);
void	constructionMessage(void);
void	fight(ScavTrap &attacker, ScavTrap &defender);
void	action(ScavTrap &attacker, ScavTrap &defender);
void	printScreen(ScavTrap &attacker, ScavTrap &defender);

#endif
