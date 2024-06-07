/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 00:40:41 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

std::string name(void) {
	std::string player;

	println(WHT << "\n                 Finally, you have arrived!!!\n");
	println(WHT << "                 We were waiting for the kingdom to send a powerful wizard to help us.");
	println(WHT << "                 The Death Couple are wreaking havoc and need to be stopped.");
	println(WHT << "                 We need you to intervene, M... I'm sorry, what is your name again?\n");
	println(WHT << "                   Please, tell us your name so we can address you properly.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	while (player.empty())
		getline(std::cin, player);
	println("\033c");

	println(RED << "\n                            YOU'LL NEVER WIN, PEASANT!!! MWAHAHAHAHAHAHAHA\n");

	return (player);
}

void	attack(ICharacter &player, ICharacter &enemy, std::string &input) {

	printScreen(player, enemy);

	println(WHT << "\n                                 Choose a magic slot to use, " << player.getName() << "!")
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	opponentsTurn(ICharacter &player, ICharacter &enemy, std::string &input) {

	printScreen(player, enemy);

	println(RED << "\n                                     " << enemy.getName() << "'s time to act!");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	println("\033c");
}

void	next(void) {
	println("\n  ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clear;
}


void	printScreen(ICharacter &player, ICharacter &enemy) {

	std::string color;

	if (enemy.getHealth() >= 150)
		color = GRN;
	else if (enemy.getHealth() >= 100)
		color = YLW;
	else if (enemy.getHealth() >= 50)
		color = PRP;
	else
		color = RED;

	println(WHT << "                                                         " << color << "                 /\\");
	println(WHT << "                                                         " << color << "                 ||");
	println(WHT << "                                   /^\\                  " << color << "    ____ (((+))) _||_");
	println(WHT << "                              /\\   \"V\"                " << color << "     /.--.\\  .-.  /.||.\\");
	println(WHT << "                             /__\\   I                   " << color << "  /.,   \\\\(0.0)// || \\\\");
	println(WHT << "                            //..\\\\  I                  " << color << "  /;`\";/\\ \\\\|m|//  ||  ;\\");
	println(WHT << "                            \\].`[/  I                   " << color << " |:   \\ \\__`:`____||__:|");
	println(WHT << "                            /l\\/j\\  (]                 " << color << "  |:    \\__ \\T/ (@~)(~@)|");
	println(WHT << "                           /. ~~ ,\\/I                   " << color << " |:    _/|     |\\_\\/  :|");
	println(WHT << "                           \\\\L__j^\\/I                 " << color << "   |:   /  |     |  \\   :|");
	println(WHT << "                            \\/--v}  I                   " << color << " |'  /   |     |   \\  '|");
	println(WHT << "                            |    |  I                    " << color << " \\_/    |     |    \\_/");
	println(WHT << "                            |    |  I                    " << color << "        |     |");
	println(WHT << "                            |    l  I                    " << color << "        |_____|");
	println(WHT << "                          _/j  L l\\_!                   " << color << "         |_____|");
	println("");
	(void)enemy;
	println("                   ╭────────────────────────╮");
	println("                   │         " << std::setw(3) << player.getHealth() << "  HP        │");
	println("                   │                        │");
	println("                   │ " << player.getMateriaGem(0) << " " << std::left << std::setw(8) << player.getMateriaType(0) << " "
									<< player.getMateriaGem(1) << " " << std::left << std::setw(8) << player.getMateriaType(1) << "│");
	println("                   │                        │");
	println("                   │ " << player.getMateriaGem(2) << " " << std::left << std::setw(8) << player.getMateriaType(2) << " "
									<< player.getMateriaGem(3) << " " << std::left << std::setw(8) << player.getMateriaType(3) << "│");
	println("                   ╰────────────────────────╯");
}
