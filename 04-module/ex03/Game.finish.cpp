/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.finish.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 21:35:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

void	Game::ending() {
	println(WHT << "\n            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │                         " << GRN << "You've saved the village!" << WHT << "                        │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │         The elders are grateful for your help and gave you a fair        │");
	println(WHT << "            │   amount of gold to compensate you for your heroism. They also allowed   │");
	println(WHT << "            │      you to take home all the Materia you've gathered on the combats.    │");
	println(WHT << "            │                        This is your final spoil:                         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [1] " << _player->getMateriaGem(0) << " " << std::left << std::setw(15) << _player->getMateriaType(0)
													<< " [2] " << _player->getMateriaGem(1) << " " << std::left << std::setw(15) << _player->getMateriaType(1) << "         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [3] " << _player->getMateriaGem(2) << " " << std::left << std::setw(15) << _player->getMateriaType(2)
													<< " [4] " << _player->getMateriaGem(3) << " " << std::left << std::setw(15) << _player->getMateriaType(3) << "         │");
	println(WHT << "            ╰──────────────────────────────────────────────────────────────────────────╯");

	next();
	gameOver();
}

void	Game::gameOver() {
	delete _player;
	delete _src;
	delete _azrael;
	delete _evanora;
	delete _ghidorah;
	exit(EXIT_SUCCESS);
}
