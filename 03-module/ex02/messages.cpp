/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 21:54:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	constructionMessage(void) {
	println(WHT << "\n  FragTrap also inherits from ClapTrap, so the construction calling is\n"
					"  the same as the previous exercise.\n");

	println("     FragTrap unknown;");
	println("     FragTrap marvin(\"Marvin\");");
	println("     FragTrap derp(\"Derp\");");
	println("     FragTrap copy(derp);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "  Again, the destructors are called in order: derived " << "\033[37;4m"
				<< "first" << DFL << WHT << ", base " << "\033[37;4m" << "after" << DFL << WHT << ".\n");
}

void	waitAndClean(void) {
	println(WHT << "\n  Press enter to continue.");
	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
}

void	fight(FragTrap &attacker, FragTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "\n     Yup... That's our life now. You need to finish them\n     so "
				<< "I can " << GRN << "continue" << WHT << " with the explanation.\n\n");

	while (input != "E") {
		printScreen(attacker, defender);
		println(WHT << "\n  What should " << attacker.getName() << " do? (" << RED
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
			println(RED << "\n          Invalid input.\n\n\n");
		}
		printScreen(attacker, defender);
		println(RED << "\n  " << defender.getName() << "'s time to act!" << WHT
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

void	action(FragTrap &attacker, FragTrap &defender) {
	std::string	input;
	int	choice = rand() % 2;

	if (attacker.getEnergyPoints() == 100)
		choice = 0;
	switch (choice) {
		case 0:
			attacker.highFivesGuys();
			if (attacker.getEnergyPoints() <= 0 || attacker.getHitPoints() <= 0)
				break ;
			input = printHighFive(defender, attacker);
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
				println("\n")
			}
			else {
				attacker.upgrade();
				attacker.beRepaired((rand() % 20) + 15);
				attacker.attack(defender);
				attacker.setEnergyCorrection(3);
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

void	printScreen(FragTrap &attacker, FragTrap &defender) {
	println("              \\_\\                              __");
	println("             (_**)                         _  |@@|");
	println("            __) #_                        / \\ \\--/ __");
	println("           ( )...()                       ) O|----|  |   __");
	println("           || | |I|                      / / \\ }{ /\\ )_ / _\\");
	println("           || | |()__/                   )/  /\\__/\\ \\__O (__");
	println("           /\\(___)                      |/  (--/\\--)    \\__/");
	println("          _-\"\"\"\"\"\"\"-_\"\"-_               /   _)(  )(_");
	println("          -,,,,,,,,- ,,-                   `---''---`");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │  L... LOVE ME? │");
	println("        │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("        │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("        │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("        ╰────────────────╯             ╰────────────────╯");
}

std::string	printHighFive(FragTrap &attacker, FragTrap &defender) {
	std::string	input;

	println("              \\_\\                              __");
	println("             (_**)                     _(\\    |@@|");
	println("            __) #_                    (__/\\__ \\--/ __");
	println("           ( )...()                      \\___|----|  |   __");
	println("           || | |I|                          \\ }{ /\\ )_ / _\\");
	println("           || | |()__/                       /\\__/\\ \\__O (__");
	println("           /\\(___)                          (--/\\--)    \\__/");
	println("          _-\"\"\"\"\"\"\"-_\"\"-_                   _)(  )(_");
	println("          -,,,,,,,,- ,,-                   `---''---`");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │  L... LOVE ME? │");
	println("        │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("        │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("        │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("        ╰────────────────╯             ╰────────────────╯");
	println(WHT << "\n  You can (" << GRN << "A" << WHT << ")ccept or (" << RED << "R" << WHT << ")eject their proposal, no pressure.");
	println(WHT << "╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "╰─➤ " << DFL;
	while (input.empty() && input != "a" && input != "A" && input != "r" && input != "R")
		getline(std::cin, input);
	println("\033c");
	return (input);
}
