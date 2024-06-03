/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 20:40:19 by julberna         ###   ########.fr       */
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

	std::string	input("not empty");
	waitAndClean();

	println(RED << "          ███▄ ▄███▓ ▒█████   ███▄ ▄███▓ ███▄ ▄███▓▓██   ██▓ ▄▄▄");
	println(RED << "         ▓██▒▀█▀ ██▒▒██▒  ██▒▓██▒▀█▀ ██▒▓██▒▀█▀ ██▒ ▒██  ██▒ ▌ █");
	println(RED << "         ▒██▒   ░██▒░ ████▓▒░▒██▒   ░██▒▒██▒   ░██▒  ░ ██▒▓░ ▒ ▌ ");
	println(RED << "         ░  ░      ░  ░ ▒ ▒░ ░  ░      ░░  ░      ░ ▓██ ░▒░  ░▄ ░");
	println(RED << "         ░      ░   ░ ░ ░ ▒  ░      ░   ░      ░    ▒ ▒ ░░      ░");
	printScreen(attacker, defender);
	println(WHT << "\n    Who the heck are you??? And why are you " << RED << "COVERED IN BLOOD" << WHT << "??");
	println(WHT << "╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "╰─➤ " << DFL;
	while (!input.empty())
		getline(std::cin, input);
	println("\033c");
	println("");
	defender.whoAmI();
	println("\n");

	while (input != "E") {
		printScreen(attacker, defender);
		println(WHT << "\n  What should " << attacker.getDiamondName() << " do? (" << RED
					<< "A" << WHT << ")ttack, (" << GRN << "H" << WHT << ")eal, ("
					<< CYN << "U" << WHT << ")pgrade or (" << PRP << "E" << WHT << ")xit.")
		println(WHT << "╭──────────────────────────────────────────────────────────────╯")
		std::cout << WHT << "╰─➤ " << DFL;
		input.clear();
		while (input.empty())
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
	int	choice = rand() % 4;

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
			println("");
			if (attacker.getHitPoints() <= 0)
				println(RED << "       Â̶͉ ̵̬̕m̸̺͝ ̸̫͐ ̶̻̓ ̷̲̀" << WHT << "I̴̲͌ ̷̨̈́.̴͍̈́" << RED << " ̵͔̐.̴̫̾ ̴͎̍.̴̝̈́ ̶̛̗ ̷̲̈́ ̷̣̎D̵̬͒ ̵̦̀e̵͕̐ ̸͔͛" << WHT << "a̵̠͠ ̸̢͐" << RED << "d̴̦̓ ̷͍͐?̸̣̀?̴̢̀");
			attacker.attack(defender);
			if (attacker.getHitPoints() > 0)
				println("");
			println("");
			break ;
		case 2:
			println("")
			if (attacker.getHitPoints() > 0)
				attacker.whoAmI();
			attacker.beRepaired(rand() % 30);
			if (attacker.getHitPoints() <= 0)
				println(WHT << "       Ẅ̶̮́ ̴̯͘h̴͓͐ ̷̳́ỵ̵̆ ̵̨̛ ̶̖̈́ ̴̩̃d̵͓͋ ̴̛̞" << RED << "i̵̬̒ ̶͔͂d̸̨͠" << WHT << " ̵̜̽ ̷̞̽ ̶̹̊ý̵̦ ̸͇̎o̸̻̕ ̴͓̃u̷̗̓ ̷̞̀ ̷͝ͅ ̸̳͝ḋ̷̘ ̴̩̾ó̵̟ ̴̰̈́ ̷̡̒ ̷̥̈t̴̝̐ ̴̬̂h̷̬̋ ̷̘̐" << RED <<"ḯ̴̥ ̸̥̈́s̸̩̎ ̴̫͝?̴̻͊" << WHT << "?̷̡͋ ̶̭͛ ̵͉̋ ̸̭̀.̵͓͊\n")
			println("");
			break ;
		case 3:
			println("")
			if (attacker.getHitPoints() > 0)
				attacker.whoAmI();
			attacker.upgrade();
			if (attacker.getHitPoints() <= 0)
				println(RED << "       Ẅ̶̼́ ̷̦̇h̷̳̔ ̴̓ͅ.̵̜̕.̴͚̑.̴͖͛ ̷̲͌" << WHT << "Ẉ̵̋ ̴̦̀h̵̘̔ ̶̜͊" << RED << "e̶͔͐ ̵̬͋r̷̖̊ ̵̜̃e̴̳͌ ̸̪̂ ̶̜̌" << WHT << " ̷̳̊a̷̩̿ ̸̱̅m̷̑ͅ" << RED << " ̸͇̓ ̴͓̈ ̷͚̉I̸̧͋ ̸̖̃?̸̄͜ ̴͕̊ ̸̭̉ ̷̧͠W̷̪̏ ̸̖̈ĥ̴̩ ̴͕͆" << WHT << "e̴͉͝ ̸͉͌r̷̦̓ ̷̜̀ẽ̴̝" << RED << " ̶̡̆'̵͕̽ ̴̝̍s̴̬͋ ̷͇̑ ̵͎́ ̶̬̾m̸̙̅ ̶͓̑o̸̩͊ ̷̝͠m̷̹̓ ̶̱̇m̶͕̂ ̴͒͜y̶̪̾" << WHT << " ̵͚́" << RED << "?̸̧͘\n")
			println("");
			break ;
	}
}

void	printScreen(DiamondTrap &attacker, DiamondTrap &defender) {
	println("                         " << RED << "           _____              _____");
	println("                         " << RED << "          |*_*_*|    ____    |*_*_*|");
	println("                         " << RED << "  _______   _\\__\\___/ __ \\____|_|_░  _______");
	println("                         " << RED << " / ___▓█ |=|░▓█   \\▒ <_+>  /   ▓░  |=|  ____ \\");
	println("                         " << RED << " ~|   ▒|\\|=|======\\\\______//======|=|/| ▓█▒|~");
	println("                         " << RED << "  |_  ░|    \\ ▓██▒ |  ◈◈▒░| ▒▓░ ░/    |  ▒ |");
	println("                         " << RED << "   \\==-|     \\▒█░  | ◈◈◈◈ |  ▒  /     |-░--|~~/");
	println("                         " << RED << "  ░▓██▒|      |  ▐ |  ◈◈░ |  ░ | ▓    |____/~/");
	println("                         " << RED << "   ▐█░ |       \\____\\____/____/ ▒    / ░  / /");
	println("                         " << RED << "   |░  |         {----------}       /____/ /");
	println("                         " << RED << "   |___|      ▓ /~~~~~~~~~~~~\\  ░  |_/~|_|/");
	println("                         " << RED << "    \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                         " << RED << "    | |      ▒  |    ||||    |     (/|| \\)");
	println("             \\_\\       " << RED << "      | |        /     |  |  ▒  \\       \\  ▒");
	println("            (_**)        " << RED << "    |▓|    ░  ░█ ▒   |  |    ▒|       ▓");
	println("           __) #_        " << RED << "      ░    ░   ▐_____|  |_____|      ▒");
	println("          ( )...()       " << RED << "     ▒         (_____)  (_____)");
	println("          || | |I|       " << RED << "             ░ |     |  |    ▒|        ░");
	println("          || | |()__/    " << RED << "      ░        |   ▒ |  |   ▒▓|");
	println("          /\\(___)       " << RED << "      ░         |/~~~\\|  |/~~~\\|    ▒");
	println("         _-\"\"\"\"\"\"\"-_\"\"-_  " << RED << "              /|___|\\  /|___|\\");
	println("         -,,,,,,,,- ,,-            " << RED << "    <_______><_______>");
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

	println("                         " << RED << "            ___");
	println("                         " << RED << "           |_|_|");
	println("                         " << RED << "           |_|_|              _____");
	println("                         " << RED << "           |_|_|     ____    |*_*_*|");
	println("                         " << RED << "  _______   _\\__\\___/ __ \\____|_|_░  _______");
	println("                         " << RED << " / ___▓█ |=|░▓█   \\▒ <_+>  /   ▓░  |=|  ____ \\");
	println("                         " << RED << " ~|   ▒|\\|=|======\\\\______//======|=|/| ▓█▒|~");
	println("                         " << RED << "  |_  ░|    \\ ▓██▒ |  ◈◈▒░| ▒▓░ ░/    |  ▒ |");
	println("                         " << RED << "   \\==-|     \\▒█░  | ◈◈◈◈ |  ▒  /     |-░--|~~/");
	println("                         " << RED << "  ░▓██▒|      |  ▐ |  ◈◈░ |  ░ | ▓    |____/~/");
	println("                         " << RED << "   ▐█░ |       \\____\\____/____/ ▒    / ░  / /");
	println("                         " << RED << "   |░  |         {----------}       /____/ /");
	println("                         " << RED << "   |___|      ▓ /~~~~~~~~~~~~\\  ░  |_/~|_|/");
	println("                         " << RED << "    \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                         " << RED << "    | |      ▒  |    ||||    |     (/|| \\)");
	println("             \\_\\       " << RED << "      | |        /     |  |  ▒  \\       \\  ▒");
	println("            (_**)        " << RED << "    |▓|    ░  ░█ ▒   |  |    ▒|       ▓");
	println("           __) #_        " << RED << "      ░    ░   ▐_____|  |_____|      ▒");
	println("          ( )...()       " << RED << "     ▒         (_____)  (_____)");
	println("          || | |I|       " << RED << "             ░ |     |  |    ▒|        ░");
	println("          || | |()__/    " << RED << "      ░        |   ▒ |  |   ▒▓|");
	println("          /\\(___)       " << RED << "      ░         |/~~~\\|  |/~~~\\|    ▒");
	println("         _-\"\"\"\"\"\"\"-_\"\"-_  " << RED << "              /|___|\\  /|___|\\");
	println("         -,,,,,,,,- ,,-            " << RED << "    <_______><_______>");
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
