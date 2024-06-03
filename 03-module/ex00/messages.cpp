/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:19:57 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:27:44 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	constructionMessage(void) {
	
	srand(time(NULL));

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

void	attack(ClapTrap &attacker, ClapTrap &defender, std::string &input) {

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
}

void	opponentsTurn(ClapTrap &attacker, ClapTrap &defender, std::string &input) {

	printScreen(attacker, defender);

	println(RED << "\n  " << defender.getName() << "'s time to act!" << WHT
					<< " Press enter to continue or 'E' to exit.");
	println(WHT << "╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	waitAndClean(void) {
	println(WHT << "\n  Press enter to continue.");

	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);

	println("\033c");
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
