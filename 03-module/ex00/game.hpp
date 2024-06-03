/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:35:27 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef GAME_HPP
# define GAME_HPP

# include "ClapTrap.hpp"

		/**
		 * @brief Waits for user to confirm and move to the next part of the program.
		 */
void	waitAndClean(void);

		/**
		 * @brief Displays ending message before destructors.
		 */
void	destructionMessage(void);

		/**
		 * @brief Displays starting message before constructors.
		 */
void	constructionMessage(void);

		/**
		 * @brief Ring fight between two robots.
		 * @param attacker Attacking robot..
		 * @param defender Defending robot.
		 */
void	fight(ClapTrap &attacker, ClapTrap &defender);

		/**
		 * @brief Retaliation of the defender AI robot.
		 * @param attacker Attacking robot.
		 * @param defender Defending robot.
		 */
void	retaliation(ClapTrap &attacker, ClapTrap &defender);

		/**
		 * @brief Displays the screen with the robots' stats.
		 * @param attacker Attacking robot.
		 * @param defender Defending robot.
		 */
void	printScreen(ClapTrap &attacker, ClapTrap &defender);

		/**
		 * @brief Asks the user for an action to perform in behalf of the attacker robot.
		 * @param attacker Attacking robot.
		 * @param defender Defending robot.
		 * @param input User input.
		 */
void	attack(ClapTrap &attacker, ClapTrap &defender, std::string &input);

		/**
		 * @brief Action of the AI defender robot.
		 * @param attacker Attacking robot.
		 * @param defender Defending robot.
		 * @param input User's confirmation that the opponent's turn can start.
		 */
void	opponentsTurn(ClapTrap &attacker, ClapTrap &defender, std::string &input);

#endif
