/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:35 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:17:25 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	fight(ScavTrap &attacker, ScavTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "\n                    Oh no, another interruption... Can you deal with it "
				<< YLW << "AGAIN" << WHT << "?\n\n");

	while (input != "E") {

		attack(attacker, defender, input);
		if (input == "E") {
			break;
		}
		else if (input == "A") {
			attacker.attack(defender);
			if (!defender.getKeeperMode())
				println("");
		}
		else if (input == "H") {
			attacker.beRepaired(rand() % 20);
			println("\n");
		}
		else if (input == "U") {
			attacker.upgrade();
			println("\n");
		}
		else {
			println(RED << "\n                         Invalid input.\n");
		}
		println("");

		opponentsTurn(attacker, defender, input);
		if (input != "E")
			retaliation(defender, attacker);
	}
}

void	retaliation(ScavTrap &attacker, ScavTrap &defender) {

	int	choice = rand() % 2;

	if (attacker.getEnergyPoints() == 50)
		choice = 0;

	switch (choice) {
		case 0:
			attacker.guardGate();
			break ;
		case 1:
			int fight = rand() % 4;
			attacker.setKeeperMode(false);
			switch (fight) {
				case 0:
					attacker.attack(defender);
					break ;
				case 1:
					println("");
					attacker.beRepaired(rand() % 20);
					break ;
				case 2:
					println("");
					attacker.upgrade();
					break ;
				case 3:
					attacker.attack(defender);
					break ;
			}
	}
	println("\n");
}
