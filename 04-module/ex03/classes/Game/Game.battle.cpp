/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.battle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:35:54 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

void	Game::battle(void) {

	Character	*enemy[3] = {_azrael, _evanora, _ghidorah};

	for (int i = 0; i < 3; i++) {
		while (!_victory) {
			fight(*enemy[i]);
			aftermath(*enemy[i]);
		}
		_victory = false;
	}
}

void	Game::fight(Character &enemy) {

	std::string	input;
	int			slot;

	enemyScream(enemy);

	while (input != "E") {

		attackMessage(enemy, input);
		if (input == "E")
			gameOver();
		println("");
		if (input == "1" || input == "2" || input == "3" || input == "4") {
			slot = std::atoi(input.c_str()) - 1;
			if (_player->getMateriaType(slot) != "Empty") {
				std::cout << "                               " << std::flush;
				if (_player->getMateriaType(slot) == "Cure")
					_player->use(slot, *_player);
				else
					_player->use(slot, enemy);
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

		retaliationMessage(enemy, input);
		if (input == "E")
			gameOver();
		retaliation(enemy);
		if (_player->getHealth() <= 0) {
			clear;
			println("");
			println(RED << "                               Ouch! "
						<< enemy.getName() << " hit you pretty bad...");
			break ;
		}
	}
}

void	Game::retaliation(Character &enemy) {
	std::string	input;
	int	choice = rand() % 4;

	std::cout << "                               " << std::flush;

	if (enemy.getMateriaType(choice) == "Cure")
		enemy.use(choice, enemy);
	else
		enemy.use(choice, *_player);

	println("");
}

void	Game::aftermath(Character &enemy) {
	if (_player->getHealth() <= 0)
		retry(enemy);
	else
		reward(enemy);
}

void	Game::retry(Character &enemy) {

	std::string	input;

	retryMessage(input);

	if (input == "G" || input == "E")
		gameOver();

	if (enemy.getName() == "Azrael") {
		_player->setHealth(PHASE1_HP + PHASE1_HP / 2);
		enemy.setHealth(AZRAEL_HP);
	}
	else if (enemy.getName() == "Evanora") {
		_player->setHealth(PHASE2_HP + PHASE2_HP / 2);
		enemy.setHealth(EVANORA_HP);
	}
	else if (enemy.getName() == "Ghidorah") {
		_player->setHealth(PHASE3_HP + PHASE3_HP / 2);
		enemy.setHealth(GHIDORAH_HP);
	}

	clear;
}

void	Game::reward(Character &enemy) {

	int			slot;
	std::string	input = "";
	AMateria	*temp;

	rewardMessage(enemy, input);

	if (input != "S") {
		slot = std::atoi(input.c_str()) - 1;
		if (_player->getMateriaType(slot) != "Empty") {
			temp = _player->getMateria(slot);
			_player->unequip(slot);
			delete temp;
		}
		_player->equip(_src->createMateria(enemy.getMateriaType(0)));
	}

	if (enemy.getName() == "Azrael")
		_player->setHealth(PHASE2_HP);
	else
		_player->setHealth(PHASE3_HP);

	_victory = true;
	clear;
}
