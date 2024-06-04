/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:28:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

void	constructionMessage(void) {

	srand(time(NULL));

	println(WHT << "\n                 Now we have Diamond, which inherits from both Scav and Frag, \n"
					"                 which then inherit from Clap. So everybody is called on initialization.\n");

	println("                    DiamondTrap unknown;");
	println("                    DiamondTrap marvin(\"Marvin\");");
	println("                    DiamondTrap shiny(\"Shiny\");");
	println("                    DiamondTrap copy(shiny);\n");
}

void	destructionMessage(void) {
	println("\033c");
	println(WHT << "                 Same old, but starting from bottom to top of the family tree:\n"
					"                 DIAMOND ─➤ FRAG ─➤ SCAV ─➤ CLAP\n");
}

void	attack(DiamondTrap &attacker, DiamondTrap &defender, std::string &input) {

	printScreen(attacker, defender);

	println(WHT << "\n                 What should " << attacker.getDiamondName() << " do? (" << RED
				<< "A" << WHT << ")ttack, (" << GRN << "H" << WHT << ")eal, ("
				<< CYN << "U" << WHT << ")pgrade or (" << PRP << "E" << WHT << ")xit.")
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	opponentsTurn(DiamondTrap &attacker, DiamondTrap &defender, std::string &input) {

	printScreen(attacker, defender);

	println(RED << "\n                 " << defender.getDiamondName() << "'s time to act!" << WHT
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

void	presentDiamond(DiamondTrap &attacker, DiamondTrap &defender) {
	std::string	input;

	println(RED << "                         ███▄ ▄███▓ ▒█████   ███▄ ▄███▓ ███▄ ▄███▓▓██   ██▓ ▄▄▄");
	println(RED << "                        ▓██▒▀█▀ ██▒▒██▒  ██▒▓██▒▀█▀ ██▒▓██▒▀█▀ ██▒ ▒██  ██▒ ▌ █");
	println(RED << "                        ▒██▒   ░██▒░ ████▓▒░▒██▒   ░██▒▒██▒   ░██▒  ░ ██▒▓░ ▒ ▌ ");
	println(RED << "                        ░  ░      ░  ░ ▒ ▒░ ░  ░      ░░  ░      ░ ▓██ ░▒░  ░▄ ░");
	println(RED << "                        ░      ░   ░ ░ ░ ▒  ░      ░   ░      ░    ▒ ▒ ░░      ░");

	printScreen(attacker, defender);

	println(WHT << "\n                   Who the heck are you??? And why are you " << RED << "COVERED IN BLOOD" << WHT << "??");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	getline(std::cin, input);

	println("\033c");
	println("");
	defender.whoAmI();
	println("\n");
}

void	amIDead(void) {
	println(RED << "                      Â̶͉ ̵̬̕m̸̺͝ ̸̫͐ ̶̻̓ ̷̲̀" << WHT << "I̴̲͌ ̷̨̈́.̴͍̈́" << RED
				<< " ̵͔̐.̴̫̾ ̴͎̍.̴̝̈́ ̶̛̗ ̷̲̈́ ̷̣̎D̵̬͒ ̵̦̀e̵͕̐ ̸͔͛" << WHT << "a̵̠͠ ̸̢͐" << RED << "d̴̦̓ ̷͍͐?̸̣̀?̴̢̀");
}

void	whyDidYou(void) {
	println(WHT << "                      Ẅ̶̮́ ̴̯͘h̴͓͐ ̷̳́ỵ̵̆ ̵̨̛ ̶̖̈́ ̴̩̃d̵͓͋ ̴̛̞" << RED << "i̵̬̒ ̶͔͂d̸̨͠" << WHT
				<< " ̵̜̽ ̷̞̽ ̶̹̊ý̵̦ ̸͇̎o̸̻̕ ̴͓̃u̷̗̓ ̷̞̀ ̷͝ͅ ̸̳͝ḋ̷̘ ̴̩̾ó̵̟ ̴̰̈́ ̷̡̒ ̷̥̈t̴̝̐ ̴̬̂h̷̬̋ ̷̘̐" << RED <<"ḯ̴̥ ̸̥̈́s̸̩̎ ̴̫͝?̴̻͊"
				<< WHT << "?̷̡͋ ̶̭͛ ̵͉̋ ̸̭̀.̵͓͊\n");
}

void	whyyy(void) {
	println(RED << "                      Ẅ̶̼́ ̷̦̇h̷̳̔ ̴̓ͅ.̵̜̕.̴͚̑.̴͖͛ ̷̲͌" << WHT << "Ẉ̵̋ ̴̦̀h̵̘̔ ̶̜͊" << RED << "e̶͔͐ ̵̬͋r̷̖̊ ̵̜̃e̴̳͌ ̸̪̂ ̶̜̌"
				<< WHT << " ̷̳̊a̷̩̿ ̸̱̅m̷̑ͅ" << RED << " ̸͇̓ ̴͓̈ ̷͚̉I̸̧͋ ̸̖̃?̸̄͜ ̴͕̊ ̸̭̉ ̷̧͠W̷̪̏ ̸̖̈ĥ̴̩ ̴͕͆" << WHT
				<< "e̴͉͝ ̸͉͌r̷̦̓ ̷̜̀ẽ̴̝" << RED << " ̶̡̆'̵͕̽ ̴̝̍s̴̬͋ ̷͇̑ ̵͎́ ̶̬̾m̸̙̅ ̶͓̑o̸̩͊ ̷̝͠m̷̹̓ ̶̱̇m̶͕̂ ̴͒͜y̶̪̾"
				<< WHT << " ̵͚́" << RED << "?̸̧͘\n");
}

void	printScreen(DiamondTrap &attacker, DiamondTrap &defender) {
	println("                                        " << RED << "           _____              _____");
	println("                                        " << RED << "          |*_*_*|    ____    |*_*_*|");
	println("                                        " << RED << "  _______   _\\__\\___/ __ \\____|_|_░  _______");
	println("                                        " << RED << " / ___▓█ |=|░▓█   \\▒ <_+>  /   ▓░  |=|  ____ \\");
	println("                                        " << RED << " ~|   ▒|\\|=|======\\\\______//======|=|/| ▓█▒|~");
	println("                                        " << RED << "  |_  ░|    \\ ▓██▒ |  ◈◈▒░| ▒▓░ ░/    |  ▒ |");
	println("                                        " << RED << "   \\==-|     \\▒█░  | ◈◈◈◈ |  ▒  /     |-░--|~~/");
	println("                                        " << RED << "  ░▓██▒|      |  ▐ |  ◈◈░ |  ░ | ▓    |____/~/");
	println("                                        " << RED << "   ▐█░ |       \\____\\____/____/ ▒    / ░  / /");
	println("                                        " << RED << "   |░  |         {----------}       /____/ /");
	println("                                        " << RED << "   |___|      ▓ /~~~~~~~~~~~~\\  ░  |_/~|_|/");
	println("                                        " << RED << "    \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                                        " << RED << "    | |      ▒  |    ||||    |     (/|| \\)");
	println("                            \\_\\       " << RED << "      | |        /     |  |  ▒  \\       \\  ▒");
	println("                           (_**)        " << RED << "    |▓|    ░  ░█ ▒   |  |    ▒|       ▓");
	println("                          __) #_        " << RED << "      ░    ░   ▐_____|  |_____|      ▒");
	println("                         ( )...()       " << RED << "     ▒         (_____)  (_____)");
	println("                         || | |I|       " << RED << "             ░ |     |  |    ▒|        ░");
	println("                         || | |()__/    " << RED << "      ░        |   ▒ |  |   ▒▓|");
	println("                         /\\(___)       " << RED << "      ░         |/~~~\\|  |/~~~\\|    ▒");
	println("                        _-\"\"\"\"\"\"\"-_\"\"-_  " << RED << "              /|___|\\  /|___|\\");
	println("                        -,,,,,,,,- ,,-            " << RED << "    <_______><_______>");
	println("");
	println("                       ╭────────────────╮             ╭────────────────╮");
	println("                       │     MARVIN     │             │      SHINY     │");
	println("                       │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("                       │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("                       │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("                       ╰────────────────╯             ╰────────────────╯");
}

std::string	printHighFive(DiamondTrap &attacker, DiamondTrap &defender) {
	std::string	input;

	println("                                        " << RED << "            ___");
	println("                                        " << RED << "           |_|_|");
	println("                                        " << RED << "           |_|_|              _____");
	println("                                        " << RED << "           |_|_|     ____    |*_*_*|");
	println("                                        " << RED << "  _______   _\\__\\___/ __ \\____|_|_░  _______");
	println("                                        " << RED << " / ___▓█ |=|░▓█   \\▒ <_+>  /   ▓░  |=|  ____ \\");
	println("                                        " << RED << " ~|   ▒|\\|=|======\\\\______//======|=|/| ▓█▒|~");
	println("                                        " << RED << "  |_  ░|    \\ ▓██▒ |  ◈◈▒░| ▒▓░ ░/    |  ▒ |");
	println("                                        " << RED << "   \\==-|     \\▒█░  | ◈◈◈◈ |  ▒  /     |-░--|~~/");
	println("                                        " << RED << "  ░▓██▒|      |  ▐ |  ◈◈░ |  ░ | ▓    |____/~/");
	println("                                        " << RED << "   ▐█░ |       \\____\\____/____/ ▒    / ░  / /");
	println("                                        " << RED << "   |░  |         {----------}       /____/ /");
	println("                                        " << RED << "   |___|      ▓ /~~~~~~~~~~~~\\  ░  |_/~|_|/");
	println("                                        " << RED << "    \\_/        |/~~~~~||~~~~~\\|     /__|\\");
	println("                                        " << RED << "    | |      ▒  |    ||||    |     (/|| \\)");
	println("                            \\_\\       " << RED << "      | |        /     |  |  ▒  \\       \\  ▒");
	println("                           (_**)        " << RED << "    |▓|    ░  ░█ ▒   |  |    ▒|       ▓");
	println("                          __) #_        " << RED << "      ░    ░   ▐_____|  |_____|      ▒");
	println("                         ( )...()       " << RED << "     ▒         (_____)  (_____)");
	println("                         || | |I|       " << RED << "             ░ |     |  |    ▒|        ░");
	println("                         || | |()__/    " << RED << "      ░        |   ▒ |  |   ▒▓|");
	println("                         /\\(___)       " << RED << "      ░         |/~~~\\|  |/~~~\\|    ▒");
	println("                        _-\"\"\"\"\"\"\"-_\"\"-_  " << RED << "              /|___|\\  /|___|\\");
	println("                        -,,,,,,,,- ,,-            " << RED << "    <_______><_______>");
	println("");
	println("                       ╭────────────────╮             ╭────────────────╮");
	println("                       │     MARVIN     │             │      SHINY     │");
	println("                       │   Health: " << std::setw(3) << attacker.getHitPoints() << "  │             │   Health: " << std::setw(3) << defender.getHitPoints() << "  │");
	println("                       │   Energy: " << std::setw(3) << attacker.getEnergyPoints() << "  │             │   Energy: " << std::setw(3) << defender.getEnergyPoints() << "  │");
	println("                       │   Damage: " << std::setw(3) << attacker.getAttackDamage() << "  │             │   Damage: " << std::setw(3) << defender.getAttackDamage() << "  │");
	println("                       ╰────────────────╯             ╰────────────────╯");
	println(WHT << "\n                 You can (" << GRN << "A" << WHT << ")ccept or (" << RED << "R" << WHT << ")eject. You've been here before...");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;
	while (input.empty() && input != "a" && input != "A" && input != "r" && input != "R")
		getline(std::cin, input);
	println("\033c");
	return (input);
}
