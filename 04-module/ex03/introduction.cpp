/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:37:45 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 16:38:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	introduction(game &game) {

	loadGame(game);
	getName(game);
	getType(game);
	giveGift(game);
	equipDark(game);
}

void	getName(game &game) {
	std::string	player;

	println("\n                 Finally, you have arrived!!!\n");
	println("                 We were waiting for the kingdom to send a powerful wizard to help us.");
	println("                 The Death Couple is wreaking havoc and need to be stopped.");
	println("                 We need you to intervene, M... I'm sorry, what is your name again?\n");
	villager();
	println(WHT << "                   Please, tell us your name so we can address you properly.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	while (player.empty())
		getline(std::cin, player);
	clear;
	game.me = new Character(player);
}

void	getType(game &game) {
	std::string	type;

	println("\n                 Great! Nice to meet you, " << game.me->getName() << ".\n");
	println("                 I can't tell by your clothes, what kind of mage are you?");
	println("                 I know Fire magic is stronger, but heard Ice is more consistent...");
	println("");
	villager();
	println(WHT << "                       Choose between " << CYN << "Ice" << WHT << " [10-20 dmg] and "
														<< RED << "Fire" << WHT << " [5-25 dmg]");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	while (type.empty() || (type != "Ice" && type != "Fire" && type != "E")) {
		getline(std::cin, type);
		for (std::string::iterator it = type.begin(); it != type.end(); it++) {
			if (it == type.begin())
				*it = (char)toupper(*it);
			else
				*it = (char)tolower(*it);
		}
	}

	clear;
	if (type == "E")
		gameOver(game);

	game.me->equip(game.src->createMateria(type));
	game.me->equip(game.src->createMateria("Cure"));
	firstEnemyType(game);
}

void	giveGift(game &game) {

	println("                 Ugh, you are perfect for the job!\n");
	println("                 Azrael uses " << game.azrael->getMateriaType(0) << " magic, so you might have a chance. Before you go,");
	println("                 take this artifact. It's been protecting our village for centuries.");
	println("                 You're our best shot, so it's worth giving it to you. Good luck, " << game.me->getName() << "!\n");
	villager();
	println(WHT << "            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │ You have received the life stone " << game.me->getMateriaGem(1) << ", it heals you by 10-20 HP when used. │");
	println(WHT << "            │        It was placed on your second Materia slot, use it wisely.         │");
	println(WHT << "            ╰──────────────────────────────────────────────────────────────────────────╯");

	next();
}
