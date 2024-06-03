/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 18:45:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef GAME_HPP
# define GAME_HPP

# include "DiamondTrap.hpp"

			/**
			 * @brief Waits for user to confirm and move to the next part of the program.
			 */
void		waitAndClean(void);

			/**
			 * @brief Displays ending message before destructors.
			 */
void		destructionMessage(void);

			/**
			 * @brief Displays starting message before constructors.
			 */
void		constructionMessage(void);

			/**
			 * @brief Ring fight between two robots.
			 * @param attacker Attacking robot..
			 * @param defender Defending robot.
			 */
void		fight(DiamondTrap &attacker, DiamondTrap &defender);

			/**
			 * @brief Retaliation of the defender AI robot.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 */
void		retaliation(DiamondTrap &attacker, DiamondTrap &defender);

			/**
			 * @brief Displays the screen with the robots' stats.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 */
void		printScreen(DiamondTrap &attacker, DiamondTrap &defender);

			/**
			 * @brief Asks the user for an action to perform in behalf of the attacker robot.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 * @param input User input.
			 */
void		attack(DiamondTrap &attacker, DiamondTrap &defender, std::string &input);

			/**
			 * @brief Action of the AI defender robot.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 * @param input User's confirmation that the opponent's turn can start.
			 */
void		opponentsTurn(DiamondTrap &attacker, DiamondTrap &defender, std::string &input);

			/**
			 * @brief Displays the high five message.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 */
std::string	printHighFive(DiamondTrap &attacker, DiamondTrap &defender);

			/**
			 * @brief Buffs only the defender, if the attacker refuses to be friends.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 */
void		enemiesBuff(DiamondTrap &attacker, DiamondTrap &defender);

			/**
			 * @brief Buffs both robots, if the attacker accepts to be friends.
			 * @param attacker Attacking robot.
			 * @param defender Defending robot.
			 */
void		friendsBuff(DiamondTrap &attacker, DiamondTrap &defender);

void	presentDiamond(DiamondTrap &attacker, DiamondTrap &defender);
void	amIDead(void);
void	whyDidYou(void);
void	whyyy(void);

#endif
