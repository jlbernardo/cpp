/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:08:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	constructionMessage(void) {

	srand(time(NULL));

	println(WHT << "\n                 Now that we inherit from ClapTrap, its constructor will be\n"
					"                 called " << "\033[37;4m" << "first" << DFL << WHT << " for every instance.\n");

	println("                    ScavTrap unknown;");
	println("                    ScavTrap marvin(\"Marvin\");");
	println("                    ScavTrap colin(\"Colin\");");
	println("                    ScavTrap copy(colin);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "                 Just like before, we also call the destructors of the base class,\n"
					"                 but " << "\033[37;4m" << "after" << DFL << WHT << " the derived class object.\n");
}

void	attack(ScavTrap &attacker, ScavTrap &defender, std::string &input) {

	printScreen(attacker, defender);

	println(WHT << "\n                 What should " << attacker.getName() << " do? (" << RED
				<< "A" << WHT << ")ttack, (" << GRN << "H" << WHT << ")eal, ("
				<< CYN << "U" << WHT << ")pgrade or (" << PRP << "E" << WHT << ")xit.")
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	opponentsTurn(ScavTrap &attacker, ScavTrap &defender, std::string &input) {

	printScreen(attacker, defender);

	println(RED << "\n                 " << defender.getName() << "'s time to act!" << WHT
				<< " Press enter to continue or 'E' to exit.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	waitAndClean(void) {
	println(WHT << "\n                 Press enter to continue.");
	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
}

void	printScreen(ScavTrap &attacker, ScavTrap &defender) {
	println("                             \\_\\");
	println("                            (_**)                            \\_/");
	println("                           __) #_                           (* *)");
	println("                          ( )...()                         __)#(__");
	println("                          || | |I|                        ( )...( )(_)");
	println("                          || | |()__/                     || |_| ||//");
	println("                          /\\(___)                      >==() | | ()/");
	println("                         _-\"\"\"\"\"\"\"-_\"\"-_                   _(___)_");
	println("                         -,,,,,,,,- ,,-                   [-]   [-]");
	println("");
	println("                       ╭────────────────╮             ╭────────────────╮");
	println("                       │     MARVIN     │             │     COLIN      │");
	println("                       │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("                       │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("                       │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("                       ╰────────────────╯             ╰────────────────╯");
}
