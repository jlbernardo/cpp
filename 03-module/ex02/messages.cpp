/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:22:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	constructionMessage(void) {

	srand(time(NULL));

	println(WHT << "\n                 FragTrap also inherits from ClapTrap, so the construction calling is\n"
					"                 the same as the previous exercise.\n");

	println("                    FragTrap unknown;");
	println("                    FragTrap marvin(\"Marvin\");");
	println("                    FragTrap derp(\"Derp\");");
	println("                    FragTrap copy(derp);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "                 Again, the destructors are called in order: derived " << "\033[37;4m"
				<< "first" << DFL << WHT << ", base " << "\033[37;4m" << "after" << DFL << WHT << ".\n");
}

void	attack(FragTrap &attacker, FragTrap &defender, std::string &input) {

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

void	opponentsTurn(FragTrap &attacker, FragTrap &defender, std::string &input) {

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

void	printScreen(FragTrap &attacker, FragTrap &defender) {
	println("                             \\_\\                              __");
	println("                            (_**)                         _  |@@|");
	println("                           __) #_                        / \\ \\--/ __");
	println("                          ( )...()                       ) O|----|  |   __");
	println("                          || | |I|                      / / \\ }{ /\\ )_ / _\\");
	println("                          || | |()__/                   )/  /\\__/\\ \\__O (__");
	println("                          /\\(___)                      |/  (--/\\--)    \\__/");
	println("                         _-\"\"\"\"\"\"\"-_\"\"-_               /   _)(  )(_");
	println("                         -,,,,,,,,- ,,-                   `---''---`");
	println("");
	println("                       ╭────────────────╮             ╭────────────────╮");
	println("                       │     MARVIN     │             │  L... LOVE ME? │");
	println("                       │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("                       │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("                       │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("                       ╰────────────────╯             ╰────────────────╯");
}

std::string	printHighFive(FragTrap &attacker, FragTrap &defender) {
	std::string	input;

	println("                             \\_\\                              __");
	println("                            (_**)                     _(\\    |@@|");
	println("                           __) #_                    (__/\\__ \\--/ __");
	println("                          ( )...()                      \\___|----|  |   __");
	println("                          || | |I|                          \\ }{ /\\ )_ / _\\");
	println("                          || | |()__/                       /\\__/\\ \\__O (__");
	println("                          /\\(___)                          (--/\\--)    \\__/");
	println("                         _-\"\"\"\"\"\"\"-_\"\"-_                   _)(  )(_");
	println("                         -,,,,,,,,- ,,-                   `---''---`");
	println("");
	println("                       ╭────────────────╮             ╭────────────────╮");
	println("                       │     MARVIN     │             │  L... LOVE ME? │");
	println("                       │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("                       │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("                       │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("                       ╰────────────────╯             ╰────────────────╯");
	println(WHT << "\n                 You can (" << GRN << "A" << WHT << ")ccept or (" << RED << "R" << WHT << ")eject their proposal, no pressure.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;
	while (input.empty() && input != "a" && input != "A" && input != "r" && input != "R")
		getline(std::cin, input);
	println("\033c");
	return (input);
}
