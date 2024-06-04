/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:02:43 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:27:18 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	fight(DiamondTrap &attacker, DiamondTrap &defender) {

	std::string	input;
	waitAndClean();
	presentDiamond(attacker, defender);

	while (input != "E") {

		attack(attacker, defender, input);
		println("");
		if (input == "E") {
			break;
		}
		else if (input == "A") {
			attacker.attack(defender);
			if (!defender.getKeeperMode())
				println("");
		}
		else if (input == "H") {
			attacker.beRepaired(rand() % 30);
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

void	retaliation(DiamondTrap &attacker, DiamondTrap &defender) {
	std::string	input;
	int	choice = rand() % 5;
	attacker.setKeeperMode(false);

	if (attacker.getHitPoints() <= 0) {
		println("");
		amIDead();
	}
	if (choice != 0 && attacker.getHitPoints() > 0) {
		println("");
		if (attacker.getHitPoints() > 0 && choice != 4 && choice != 1)
			attacker.whoAmI();
	}

	switch (choice) {
		case 0:
			attacker.highFivesGuys();
			if (attacker.getEnergyPoints() > 0 && attacker.getHitPoints() > 0) {
				println("");
				input = printHighFive(defender, attacker);

				if (input == "a" || input == "A") {
					println("");
					friendsBuff(attacker, defender);
					println("");
				}
				else {
					enemiesBuff(attacker, defender);
				}
			}
			else {
				println("");
			}
			break ;
		case 1:
			attacker.attack(defender);
			if (attacker.getHitPoints() > 0)
				println("");
			break ;
		case 2:
			attacker.beRepaired(30 + rand() % 30);
			if (attacker.getHitPoints() <= 0)
				println("");
			break ;
		case 3:
			attacker.upgrade();
			if (attacker.getHitPoints() <= 0)
				println("");
			break ;
		case 4:
			attacker.guardGate();
			if (attacker.getHitPoints() > 0)
				println("");
			break ;
	}
	println("");
}

void	friendsBuff(DiamondTrap &attacker, DiamondTrap &defender) {
	int buff;

	buff = rand() % 2;
	switch (buff) {
		case 0:
			attacker.beRepaired(rand() % 30);
			break ;
		case 1:
			attacker.upgrade();
			break ;
	}
	attacker.setEnergyCorrection(1);

	buff = rand() % 2;
	switch (buff) {
		case 0:
			defender.beRepaired(rand() % 30);
			break ;
		case 1:
			defender.upgrade();
			break ;
	}
	defender.setEnergyCorrection(1);
}

void	enemiesBuff(DiamondTrap &attacker, DiamondTrap &defender) {

	attacker.upgrade();
	attacker.beRepaired((rand() % 20) + 15);
	attacker.attack(defender);
	attacker.setEnergyCorrection(3);
}
