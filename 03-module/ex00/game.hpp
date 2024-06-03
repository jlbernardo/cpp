/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 14:39:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ClapTrap.hpp"

void	waitAndClean(void);
void	destructionMessage(void);
void	constructionMessage(void);
void	fight(ClapTrap &attacker, ClapTrap &defender);
void	retaliation(ClapTrap &attacker, ClapTrap &defender);
void	printScreen(ClapTrap &attacker, ClapTrap &defender);
void	attack(ClapTrap &attacker, ClapTrap &defender, std::string &input);
void	opponentsTurn(ClapTrap &attacker, ClapTrap &defender, std::string &input);

#endif
