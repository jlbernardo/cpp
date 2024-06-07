/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 00:51:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	fight(ICharacter &player, ICharacter &enemy) {

	std::string	input;
	int			slot;

	while (input != "E") {

		attack(player, enemy, input);
		println("");
		if (input == "E") {
			break ;
		}
		else if (input == "1" || input == "2" || input == "3" || input == "4") {
			slot = std::atoi(input.c_str()) - 1;
			if (player.getMateriaType(slot) != "Empty") {
				std::cout << "                               " << std::flush;
				if (player.getMateriaType(slot) == "Cure")
					player.use(slot, player);
				else
					player.use(slot, enemy);
			}
			else {
				println(RED << "                               No materia on that slot...");
			}
		}
		else {
			println(RED << "                               Invalid input.");
		}
		if (enemy.getHealth() <= 0) {
			clear;
			println("");
			println(GRN << "                               You have defeated " << enemy.getName() << "!");
			break ;
		}
		println("");

		opponentsTurn(player, enemy, input);
		println("");
		if (input != "E")
			retaliation(player, enemy);
		if (player.getHealth() <= 0) {
			clear;
			println("");
			println(RED << "                               You have been defeated by " << enemy.getName() << "!");
			break ;
		}
	}
}

void	retaliation(ICharacter &player, ICharacter &enemy) {
	std::string	input;
	int	choice = rand() % 2;

	std::cout << "                               " << std::flush;

	if (choice == 1)
		enemy.use(choice, enemy);
	else
		enemy.use(choice, player);

	println("");
}
