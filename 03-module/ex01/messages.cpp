/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 19:33:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	constructionMessage(void) {
	println(WHT << "\n  Now that we inherit from ClapTrap, its constructor will be\n"
					"  called " << "\033[37;4m" << "first" << DFL << WHT << " for every instance.\n");

	println("     ScavTrap unknown;");
	println("     ScavTrap marvin(\"Marvin\");");
	println("     ScavTrap colin(\"Colin\");");
	println("     ScavTrap copy(colin);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "  Just like before, we also call the destructors of the base class,\n"
					"  but " << "\033[37;4m" << "after" << DFL << WHT << " the derived class object.\n");
}

void	waitAndClean(void) {
	println(WHT << "\n  Press enter to continue.");
	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
}

void	fight(ScavTrap &attacker, ScavTrap &defender) {

	std::string	input;
	waitAndClean();
	println(WHT << "     Oh no, another interruption... Can you deal with it "
				<< YLW << "AGAIN" << WHT << "?\n\n\n");

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
			attacker.attack(defender);
			println("");
			if (!defender.getKeeperMode())
				println("");
		}
		else if (input == "H") {
			attacker.beRepaired(rand() % 20);
			println("\n\n");
		}
		else if (input == "U") {
			attacker.upgrade();
			println("\n\n");
		}
		else {
			println(RED << "          Invalid input.\n\n\n");
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

void	action(ScavTrap &attacker, ScavTrap &defender) {
	int	choice = rand() % 2;

	switch (choice) {
		case 0:
			attacker.guardGate();
			println("\n");
			break ;
		case 1:
			int fight = rand() % 4;
			attacker.setKeeperMode(false);
			switch (fight) {
				case 0:
					attacker.attack(defender);
					println("\n");
					break ;
				case 1:
					attacker.beRepaired(rand() % 20);
					println("\n\n");
					break ;
				case 2:
					attacker.upgrade();
					println("\n\n");
					break ;
				case 3:
					attacker.attack(defender);
					println("\n");
					break ;
			}
	}
}

void	printScreen(ScavTrap &attacker, ScavTrap &defender) {
	println("              \\_\\");
	println("             (_**)                            \\_/");
	println("            __) #_                           (* *)");
	println("           ( )...()                         __)#(__");
	println("           || | |I|                        ( )...( )(_)");
	println("           || | |()__/                     || |_| ||//");
	println("           /\\(___)                      >==() | | ()/");
	println("          _-\"\"\"\"\"\"\"-_\"\"-_                   _(___)_");
	println("          -,,,,,,,,- ,,-                   [-]   [-]");
	println("");
	println("        ╭────────────────╮             ╭────────────────╮");
	println("        │     MARVIN     │             │     COLIN      │");
	println("        │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("        │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("        │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("        ╰────────────────╯             ╰────────────────╯");
}
