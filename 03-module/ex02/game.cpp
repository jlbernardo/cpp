/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:29:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:23:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	fight(FragTrap &attacker, FragTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "\n                    Yup... That's our life now. You need to finish them"
				<< "\n                    so I can " << GRN << "continue" << WHT << " with the explanation.\n\n");

	while (input != "E") {

		attack(attacker, defender, input);
		println("");
		if (input == "E") {
			break;
		}
		else if (input == "A") {
			attacker.attack(defender);
		}
		else if (input == "H") {
			attacker.beRepaired(rand() % 30);
			println("");
		}
		else if (input == "U") {
			attacker.upgrade();
			println("");
		}
		else {
			println(RED << "                         Invalid input.\n");
		}
		println("\n");

		opponentsTurn(attacker, defender, input);
		if (input != "E")
			retaliation(defender, attacker);
	}
}

void	retaliation(FragTrap &attacker, FragTrap &defender) {
	std::string	input;
	int	choice = rand() % 2;

	if (attacker.getEnergyPoints() == 100)
		choice = 0;

	switch (choice) {
		case 0:
			attacker.highFivesGuys();

			if (attacker.getEnergyPoints() > 0 && attacker.getHitPoints() > 0) {
				input = printHighFive(defender, attacker);

				if (input == "a" || input == "A") {
					println("");
					friendsBuff(attacker, defender);
					println("")
				}
				else {
					enemiesBuff(attacker, defender);
				}
				println("");
			}
			break ;

		case 1:
			int fight = rand() % 3;
			println("");

			switch (fight) {
				case 0:
					attacker.attack(defender);
					break ;
				case 1:
					attacker.beRepaired(rand() % 30);
					println("");
					break ;
				case 2:
					attacker.upgrade();
					println("");
					break ;
			}
			println("\n");
	}
}

void	friendsBuff(FragTrap &attacker, FragTrap &defender) {
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

void	enemiesBuff(FragTrap &attacker, FragTrap &defender) {

	attacker.upgrade();
	attacker.beRepaired((rand() % 20) + 15);
	attacker.attack(defender);
	attacker.setEnergyCorrection(3);
}
