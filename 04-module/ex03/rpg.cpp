/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/09 00:23:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	introduction(game &game) {
	getName(game);
	getType(game);
}

void	gameStart(game &game) {

	while (!game.victory) {
		println(RED << "\n                            YOU'LL NEVER WIN, PEASANT!!! MWAHAHAHAHAHAHAHA\n");
		fight(game, *game.me, *game.azrael);
		aftermath(game, *game.azrael);
	}
	game.victory = false;
	while (!game.victory) {
		println(RED << "\n                            AZRAAAAA!!!   NOOOOO!!!   YOU'LL PAY, DWARF!!!!\n");
		fight(game, *game.me, *game.evanora);
		aftermath(game, *game.evanora);
	}
	game.victory = false;
	while (!game.victory) {
		println(RED << "\n                            RRRAAAAAAGRRWWWWWRWRWRWWW!!!!!!!!!!!!!!!!!!!!\n");
		fight(game, *game.me, *game.ghidorah);
		aftermath(game, *game.ghidorah);
	}
}

void	ending(game &game) {
	println(WHT << "\n            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │                         " << GRN << "You've saved the village!" << WHT << "                        │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │         The elders are grateful for your help and gave you a fair        │");
	println(WHT << "            │   amount of gold to compensate you for your heroism. They also allowed   │");
	println(WHT << "            │      you to take home all the Materia you've gathered on the combats.    │");
	println(WHT << "            │                        This is your final spoil:                         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [1] " << game.me->getMateriaGem(0) << " " << std::left << std::setw(15) << game.me->getMateriaType(0)
													<< " [2] " << game.me->getMateriaGem(1) << " " << std::left << std::setw(15) << game.me->getMateriaType(1) << "         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [3] " << game.me->getMateriaGem(2) << " " << std::left << std::setw(15) << game.me->getMateriaType(2)
													<< " [4] " << game.me->getMateriaGem(3) << " " << std::left << std::setw(15) << game.me->getMateriaType(3) << "         │");
	println(WHT << "            ╰──────────────────────────────────────────────────────────────────────────╯");

	next();
	gameOver(game);
}
