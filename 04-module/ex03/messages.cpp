/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/08 23:46:41 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	attack(ICharacter &player, ICharacter &enemy, std::string &input) {

	printScreen(player, enemy);

	println(WHT << "\n                                 Choose a magic slot to use, " << player.getName() << "!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clear;
}

void	opponentsTurn(ICharacter &player, ICharacter &enemy, std::string &input) {

	printScreen(player, enemy);

	println(RED << "\n                                     " << enemy.getName() << "'s time to act!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clear;
}

void	next(void) {
	println("\n            ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clear;
}


void	printScreen(ICharacter &player, ICharacter &enemy) {

	std::string color;

	if (enemy.getHealth() >= PHASE1_HP * 0.8)
		color = GRN;
	else if (enemy.getHealth() >= PHASE1_HP * 0.4)
		color = YLW;
	else
		color = RED;

	battle(enemy, color);
	println("                                                                           HP " << enemy.getHealth());
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
