/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:25:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	fight(ClapTrap &attacker, ClapTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "                  Now let's make them " << RED << "fight" << WHT << ".\n\n");

	while (input != "E") {

		attack(attacker, defender, input);
		if (input == "E") {
			break;
		}
		else if (input == "A") {
			attacker.attack(defender);
			println("");
		}
		else if (input == "H") {
			attacker.beRepaired(rand() % 3);
			println("\n");
		}
		else if (input == "U") {
			attacker.upgrade();
			println("\n");
		}
		else {
			println(RED << "          Invalid input.\n\n");
		}

		opponentsTurn(attacker, defender, input);
		if (input != "E")
			retaliation(defender, attacker);
	}
}

void	retaliation(ClapTrap &defender, ClapTrap &attacker) {

	if (defender.getAttackDamage() >= 5) {
		defender.attack(attacker);
	}
	else if (defender.getHitPoints() <= 3) {
		defender.beRepaired(rand() % 3);
		println("");
	}
	else if (defender.getAttackDamage() == 0) {
		defender.upgrade();
		println("");
	}
	else {
		int	choice = rand() % 2;
		switch (choice) {
			case 0:
				defender.attack(attacker);
				break;
			case 1:
				defender.upgrade();
				println("");
				break;
		}
	}
	println("");
}
