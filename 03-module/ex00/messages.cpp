/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 21:17:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	constructionMessage(void) {
	println(WHT << "\n  Let's first create some ClapTrap instances and see how they behave.\n");

	println("     ClapTrap unknown;");
	println("     ClapTrap marvin(\"Marvin\");");
	println("     ClapTrap hactar(\"Hactar\");");
	println("     ClapTrap copy(hactar);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "  In the end, the destructors are called.\n");
}

void	waitAndClean(void) {
	println(WHT << "\n  Press enter to continue.");
	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
}

void	fight(ClapTrap &attacker, ClapTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "                  Now let's make them " << RED << "fight" << WHT << ".\n\n");

	while (input != "E") {
		printScreen(attacker, defender);
		println(WHT << "\n  What should " << attacker.getName() << " do? (" << RED << "A"
					<< WHT << ")ttack, (" << GRN << "H" << WHT << ")eal, (" << CYN << "U"
					<< WHT << ")pgrade or (" << PRP << "E" << WHT << ")xit.")
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
		printScreen(attacker, defender);
		println(RED << "\n  " << defender.getName() << "'s time to act!" << WHT
					<< " Press enter to continue or 'E' to exit.");
		println(WHT << "╭──────────────────────────────────────────────────────────────╯")
		std::cout << WHT << "╰─➤ " << DFL;
		input = "not empty";
		while (!input.empty() && input != "e")
			getline(std::cin, input);
		if (input == "E" || input == "e") {
			break;
		}
		println("\033c");
		action(defender, attacker);
	}
}

void	action(ClapTrap &attacker, ClapTrap &defender) {
	if (attacker.getAttackDamage() >= 5) {
		attacker.attack(defender);
		println("");
	}
	else if (attacker.getHitPoints() <= 3) {
		attacker.beRepaired(rand() % 3);
		println("\n");
	}
	else if (attacker.getAttackDamage() == 0) {
		attacker.upgrade();
		println("\n");
	}
	else {
		int	choice = rand() % 2;
		switch (choice) {
			case 0:
				attacker.attack(defender);
				println("");
				break;
			case 1:
				attacker.upgrade();
				println("\n");
				break;
		}
	}
}

void	printScreen(ClapTrap &attacker, ClapTrap &defender) {
	println("              \\_\\                            ,     ,");
	println("             (_**)                          (\\____/)");
	println("            __) #_                           (_oo_)");
	println("           ( )...()                           (O)");
	println("           || | |I|                          __||__    \\)");
	println("           || | |()__/                    []/______\\[] /");
	println("           /\\(___)                        / \\______/ \\/");
	println("          _-\"\"\"\"\"\"\"-_\"\"-_                /    /__\\");
	println("          -,,,,,,,,- ,,-                (\\   /____\\");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │     HACTAR     │");
	println("        │   Health: " << std::setw(2) << attacker.getHitPoints() << "   │             │   Health: " << std::setw(2) << defender.getHitPoints() << "   │");
	println("        │   Energy: " << std::setw(2) << attacker.getEnergyPoints() << "   │             │   Energy: " << std::setw(2) << defender.getEnergyPoints() << "   │");
	println("        │   Damage: " << std::setw(2) << attacker.getAttackDamage() << "   │             │   Damage: " << std::setw(2) << defender.getAttackDamage() << "   │");
	println("        ╰────────────────╯             ╰────────────────╯");
}
