/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/08 23:55:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	fight(game &game, ICharacter &player, ICharacter &enemy) {

	std::string	input;
	int			slot;

	while (input != "E") {

		attack(player, enemy, input);
		if (input == "E")
			gameOver(game);
		println("");
		if (input == "1" || input == "2" || input == "3" || input == "4") {
			slot = std::atoi(input.c_str()) - 1;
			if (player.getMateriaType(slot) != "Empty") {
				std::cout << "                               " << std::flush;
				if (player.getMateriaType(slot) == "Cure")
					player.use(slot, player);
				else
					player.use(slot, enemy);
			}
			else
				println(RED << "                               No materia on that slot...");
		}
		else
			println(RED << "                               Invalid input.");
		if (enemy.getHealth() <= 0) {
			clear;
			println("");
			break ;
		}
		println("");

		opponentsTurn(player, enemy, input);
		println("");
		if (input == "E")
			gameOver(game);
		retaliation(player, enemy);
		if (player.getHealth() <= 0) {
			clear;
			println("");
			println(RED << "                               Ouch! "
						<< enemy.getName() << " hit you pretty bad...");
			break ;
		}
	}
}

void	retaliation(ICharacter &player, ICharacter &enemy) {
	std::string	input;
	int	choice = rand() % 4;

	std::cout << "                               " << std::flush;

	if (enemy.getMateriaType(choice) == "Cure")
		enemy.use(choice, enemy);
	else
		enemy.use(choice, player);

	println("");
}

void	aftermath(game &game, ICharacter &enemy) {
	if (game.me->getHealth() <= 0)
		retry(game, enemy);
	else
		reward(game, enemy);
}
