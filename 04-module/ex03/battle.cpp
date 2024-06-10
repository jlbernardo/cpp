/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 16:32:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	battle(game &game) {

	ICharacter	*enemy[3] = {game.azrael, game.evanora, game.ghidorah};

	for (int i = 0; i < 3; i++) {
		while (!game.victory) {
			fight(game, *game.me, *enemy[i]);
			aftermath(game, *enemy[i]);
		}
		game.victory = false;
	}
}

void	fight(game &game, ICharacter &player, ICharacter &enemy) {

	std::string	input;
	int			slot;

	enemyScream(enemy);

	while (input != "E") {

		attackMessage(player, enemy, input);
		if (input == "E")
			gameOver(game);
		println("");
		if (input == "1" || input == "2" || input == "3" || input == "4") {
			slot = std::atoi(input.c_str()) - 1;
			if (player.getMateriaType(slot) != "Empty") {
				std::cout << "                               " << std::flush;
				if (player.getMateriaType(slot) == "Cure")
					player.use(slot, player);
				else
					player.use(slot, enemy);
			}
			else
				println(RED << "                               No materia on that slot...");
		}
		else
			println(RED << "                               Invalid input.");
		if (enemy.getHealth() <= 0) {
			clear;
			println("");
			break ;
		}
		println("");

		retaliationMessage(player, enemy, input);
		if (input == "E")
			gameOver(game);
		retaliation(player, enemy);
		if (player.getHealth() <= 0) {
			clear;
			println("");
			println(RED << "                               Ouch! "
						<< enemy.getName() << " hit you pretty bad...");
			break ;
		}
	}
}

void	retaliation(ICharacter &player, ICharacter &enemy) {
	std::string	input;
	int	choice = rand() % 4;

	std::cout << "                               " << std::flush;

	if (enemy.getMateriaType(choice) == "Cure")
		enemy.use(choice, enemy);
	else
		enemy.use(choice, player);

	println("");
}

void	aftermath(game &game, ICharacter &enemy) {
	if (game.me->getHealth() <= 0)
		retry(game, enemy);
	else
		reward(game, enemy);
}

void	retry(game &game, ICharacter &enemy) {

	std::string	input;

	retryMessage(game, input);

	if (input == "G" || input == "E")
		gameOver(game);

	if (enemy.getName() == "Azrael") {
		game.me->setHealth(PHASE1_HP + PHASE1_HP / 2);
		enemy.setHealth(AZRAEL_HP);
	}
	else if (enemy.getName() == "Evanora") {
		game.me->setHealth(PHASE2_HP + PHASE2_HP / 2);
		enemy.setHealth(EVANORA_HP);
	}
	else if (enemy.getName() == "Ghidorah") {
		game.me->setHealth(PHASE3_HP + PHASE3_HP / 2);
		enemy.setHealth(GHIDORAH_HP);
	}

	clear;
}

void	reward(game &game, ICharacter &enemy) {

	int			slot;
	std::string	input = "";
	AMateria	*temp;

	rewardMessage(game, enemy, input);
	
	if (input != "S") {
		slot = std::atoi(input.c_str()) - 1;
		if (game.me->getMateriaType(slot) != "Empty") {
			temp = game.me->getMateria(slot);
			game.me->unequip(slot);
			delete temp;
		}
		game.me->equip(game.src->createMateria(enemy.getMateriaType(0)));
	}

	if (enemy.getName() == "Azrael")
		game.me->setHealth(PHASE2_HP);
	else
		game.me->setHealth(PHASE3_HP);

	game.victory = true;
	clear;
}
