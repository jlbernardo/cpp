/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 15:37:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

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

void	gameOver(game &game) {
	delete game.me;
	delete game.src;
	delete game.azrael;
	delete game.evanora;
	delete game.ghidorah;
	exit(EXIT_SUCCESS);
}
