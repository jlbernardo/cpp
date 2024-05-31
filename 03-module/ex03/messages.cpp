/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/05/30 21:21:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	constructionMessage(void) {
	println(WHT << "\n  Now we have Diamond, which inherits from both Scav and Frag, \n"
					"  which then inherit from Clap. So everybody is called on initialization.\n");

	println("     DiamondTrap unknown;");
	println("     DiamondTrap marvin(\"Marvin\");");
	println("     DiamondTrap shiny(\"Shiny\");");
	println("     DiamondTrap copy(shiny);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "  Same old, but starting from bottom to top of the family tree:\n"
					"  DIAMOND ─➤ FRAG ─➤ SCAV ─➤ CLAP\n");
}

void	waitAndClean(void) {
	println(WHT << "\n  Press enter to continue.");
	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
}

void	fight(DiamondTrap &attacker, DiamondTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "\n     Yup... That's our life now. You need to finish them\n     so "
				<< "I can " << GRN << "continue" << WHT << " with the explanation.\n\n");

	while (input != "E") {
		printScreen(attacker, defender);
		println(WHT << "\n  What should " << attacker.getDiamondName() << " do? (" << RED
					<< "A" << WHT << ")ttack, (" << GRN << "H" << WHT << ")eal, ("
					<< CYN << "U" << WHT << ")pgrade or (" << PRP << "E" << WHT << ")xit.")
		println(WHT << "╭──────────────────────────────────────────────────────────────╯")
		std::cout << WHT << "╰─➤ " << DFL;
		std::getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
		println("\033c");
		if (input == "E") {
			break;
		}
		else if (input == "A") {
			println("");
			attacker.attack(defender);
			println("\n");
		}
		else if (input == "H") {
			println("");
			attacker.beRepaired(rand() % 30);
			println("\n\n");
		}
		else if (input == "U") {
			println("");
			attacker.upgrade();
			println("\n\n");
		}
		else {
			println(RED << "\n\n          Invalid input.\n\n");
		}
		printScreen(attacker, defender);
		println(RED << "\n  " << defender.getDiamondName() << "'s time to act!" << WHT
					<< " Press enter to continue or 'E' to exit.");
		println(WHT << "╭──────────────────────────────────────────────────────────────╯")
		std::cout << WHT << "╰─➤ " << DFL;
		input = "not empty";
		while (!input.empty() && input != "e" && input != "E")
			getline(std::cin, input);
		if (input == "E" || input == "e") {
			break;
		}
		println("\033c");
		action(defender, attacker);
	}
}

void	action(DiamondTrap &attacker, DiamondTrap &defender) {
	std::string	input;
	int	choice = rand() % 2;

	if (attacker.getEnergyPoints() == 100)
		choice = 0;
	switch (choice) {
		case 0:
			attacker.highFivesGuys();
			if (attacker.getEnergyPoints() <= 0 || attacker.getHitPoints() <= 0)
				break ;
			input = printHighFive(attacker, defender);
			if (input == "a" || input == "A") {
				int buff = rand() % 2;
				println("");
				switch (buff) {
					case 0:
						attacker.beRepaired(rand() % 30);
						break ;
					case 1:
						attacker.upgrade();
						break ;
				}
				buff = rand() % 2;
				switch (buff) {
					case 0:
						defender.beRepaired(rand() % 30);
						break ;
					case 1:
						defender.upgrade();
						break ;
				}
				println("\n")
			}
			else {
				attacker.upgrade();
				attacker.beRepaired((rand() % 20) + 15);
				attacker.attack(defender);
				println("");
				break ;
			}
			break ;
		case 1:
			int fight = rand() % 3;

			switch (fight) {
				case 0:
					println("");
					attacker.attack(defender);
					println("\n");
					break ;
				case 1:
					println("")
					attacker.beRepaired(rand() % 30);
					println("\n\n");
					break ;
				case 2:
					println("")
					attacker.upgrade();
					println("\n\n");
					break ;
			}
	}
}

void	printScreen(DiamondTrap &attacker, DiamondTrap &defender) {
	println("");
	println("");
	println("                                    _____              _____");
	println("                                   |*_*_*|    ____    |*_*_*|");
	println("                           _______   _\\__\\___/ __ \\____|_|_   _______");
	println("                          / ____  |=|      \\  <_+>  /      |=|  ____ \\");
	println("                          ~|    |\\|=|======\\______//======|=|/|    |~");
	println("                           |_   |    \\      |      |      /    |    |");
	println("                            \\==-|     \\     |  2D  |     /     |----|~~/");
	println("                            |   |      |    |      |    |      |____/~/");
	println("                            |   |       \\____\\____/____/      /    / /");
	println("                            |   |         {----------}       /____/ /");
	println("                            |___|        /~~~~~~~~~~~~\\     |_/~|_|/");
	println("                             \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                             | |         |    ||||    |     (/|| \\)");
	println("             \\_\\             | |        /     |  |     \\       \\");
	println("            (_**)            |_|        |     |  |     |");
	println("           __) #_                       |_____|  |_____|");
	println("          ( )...()                      (_____)  (_____)");
	println("          || | |I|                      |     |  |     |");
	println("          || | |()__/                   |     |  |     |");
	println("          /\\(___)                       |/~~~\\|  |/~~~\\|");
	println("         _-\"\"\"\"\"\"\"-_\"\"-_                /|___|\\  /|___|\\");
	println("         -,,,,,,,,- ,,-                <_______><_______>");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │      SHINY     │");
	println("        │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("        │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("        │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("        ╰────────────────╯             ╰────────────────╯");
}

std::string	printHighFive(DiamondTrap &attacker, DiamondTrap &defender) {
	std::string	input;

	println("                                     ___");
	println("                                    |_|_|");
	println("                                    |_|_|              _____");
	println("                                    |_|_|     ____    |*_*_*|");
	println("                           _______   _\\__\\___/ __ \\____|_|_   _______");
	println("                          / ____  |=|      \\  <_+>  /      |=|  ____ \\");
	println("                          ~|    |\\|=|======\\______//======|=|/|    |~");
	println("                           |_   |    \\      |      |      /    |    |");
	println("                            \\==-|     \\     |  2D  |     /     |----|~~/");
	println("                            |   |      |    |      |    |      |____/~/");
	println("                            |   |       \\____\\____/____/      /    / /");
	println("                            |   |         {----------}       /____/ /");
	println("                            |___|        /~~~~~~~~~~~~\\     |_/~|_|/");
	println("                             \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                             | |         |    ||||    |     (/|| \\)");
	println("             \\_\\             | |        /     |  |     \\       \\");
	println("            (_**)            |_|        |     |  |     |");
	println("           __) #_                       |_____|  |_____|");
	println("          ( )...()                      (_____)  (_____)");
	println("          || | |I|                      |     |  |     |");
	println("          || | |()__/                   |     |  |     |");
	println("          /\\(___)                       |/~~~\\|  |/~~~\\|");
	println("         _-\"\"\"\"\"\"\"-_\"\"-_                /|___|\\  /|___|\\");
	println("         -,,,,,,,,- ,,-                <_______><_______>");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │      SHINY     │");
	println("        │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("        │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("        │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("        ╰────────────────╯             ╰────────────────╯");
	println(WHT << "\n  You can (" << GRN << "A" << WHT << ")ccept or (" << RED << "R" << WHT << ")eject. You've been here before...");
	println(WHT << "╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "╰─➤ " << DFL;
	while (input.empty() && input != "a" && input != "A" && input != "r" && input != "R")
		getline(std::cin, input);
	println("\033c");
	return (input);
}
