/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialogues.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:05:05 by julberna          #+#    #+#             */
/*   Updated: 2024/06/09 00:26:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

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

	if (type == "E")
		gameOver(game);

	clear;
	game.me->equip(game.src->createMateria(type));
	firstEnemyType(game);

	giveGift(game);
}

void	giveGift(game &game) {

	println("                 Ugh, you are perfect for the job!\n");
	println("                 Azrael uses " << game.azrael->getMateriaType(0) << " magic, so you might have a chance. Before you go,");
	println("                 take this artifact. It's been protecting our village for centuries.");
	println("                 You're our best shot, so it's worth giving it to you. Good luck, " << game.me->getName() << "!\n");
	villager();

	game.me->equip(game.src->createMateria("Cure"));

	println(WHT << "            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │ You have received the life stone " << game.me->getMateriaGem(1) << ", it heals you by 10-20 HP when used. │");
	println(WHT << "            │        It was placed on your second Materia slot, use it wisely.         │");
	println(WHT << "            ╰──────────────────────────────────────────────────────────────────────────╯");

	next();
}

void	retry(game &game, ICharacter &enemy) {

	std::string	input;
	int			hp = PHASE1_HP;

	println("");
	println("                 We will perish if you give up, but I understand if you can't take it anymore.");
	println("                 I think... Here, eat this, it should make you a little stronger for the next try.");
	println("                 We really need your help, " << game.me->getName() << ". Please, don't give up!\n");
	villager();
	println(WHT << "                 Your HP was increased greatly. You can [" << GRN << "R" << WHT << "]etry or ["
										<< RED << "G" << WHT << "]ive up.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	while (input.empty() || (input != "R" && input != "G")) {
		getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
	}

	if (input == "G" || input == "E")
		gameOver(game);

	if (enemy.getName() == "Evanora")
		hp = PHASE2_HP;
	else if (enemy.getName() == "Ghidorah")
		hp = PHASE3_HP;

	game.me->setHealth(hp);
	game.me->modHealth(hp / 2);
	enemy.setHealth(PHASE1_HP);

	clear;
}

void	reward(game &game, ICharacter &enemy) {

	int			space = 6;
	int			hp = PHASE1_HP;
	int			slot;
	std::string	input = "";
	AMateria	*temp;

	println(WHT << "            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │                  " << GRN << "You have successfully defeated " << std::left << std::setw(8) << enemy.getName() << WHT << std::setw(17) << " " << "│");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │        A " << enemy.getMateriaGem(0) << " " << enemy.getMateriaType(0) << " gem was dropped on the ground. You can equip it" << std::setw(space) << " " << "│");
	println(WHT << "            │      on one of your free slots or choose one of the occupied ones to     │");
	println(WHT << "            │   be replaced. If you don't want to equip this Materia, you can Skip it  │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [1] " << game.me->getMateriaGem(0) << " " << std::left << std::setw(15) << game.me->getMateriaType(0)
													<< " [2] " << game.me->getMateriaGem(1) << " " << std::left << std::setw(15) << game.me->getMateriaType(1) << "         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [3] " << game.me->getMateriaGem(2) << " " << std::left << std::setw(15) << game.me->getMateriaType(2)
													<< " [4] " << game.me->getMateriaGem(3) << " " << std::left << std::setw(15) << game.me->getMateriaType(3) << "         │");
	println(WHT << "            ├──────────────────────────────────────────────────────────────────────────╯");
	println(WHT << "            │")
	std::cout << WHT << "            ╰─➤ " << DFL;

	while (input.empty() || (input != "1" && input != "2" && input != "3" && input != "4" && input != "S" && input != "E")) {
		getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
	}

	if (input == "S")
		return ;
	else if (input == "E")
		gameOver(game);

	slot = std::atoi(input.c_str()) - 1;
	if (game.me->getMateriaType(slot) != "Empty") {
		temp = game.me->getMateria(slot);
		game.me->unequip(slot);
		delete temp;
	}
	game.me->equip(game.src->createMateria(enemy.getMateriaType(0)));

	if (enemy.getName() == "Evanora")
		hp = PHASE2_HP;
	else if (enemy.getName() == "Ghidorah")
		hp = PHASE3_HP;

	game.me->setHealth(hp);
	game.me->modHealth(hp / 2);
	game.victory = true;

	clear;
}
