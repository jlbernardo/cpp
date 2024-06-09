/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/09 00:08:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPG_HPP
# define RPG_HPP

# include "IMateriaSource.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "Fire.hpp"
# include "Dark.hpp"
# include "Thunder.hpp"
# include "Character.hpp"
# include "general.hpp"
# include <limits>
# include <string>
# include <iomanip>

struct game {
	bool			victory;
	ICharacter		*ghidorah;
	ICharacter		*evanora;
	ICharacter		*azrael;
	ICharacter		*me;
	IMateriaSource	*src;
};

void	next(void);
void	villager(void);
void	ending(game &game);
void	getName(game &game);
void	getType(game &game);
void	loadGame(game &game);
void	giveGift(game &game);
void	gameOver(game &game);
void	gameStart(game &game);
void	introduction(game &game);
void	firstEnemyType(game &game);
void	retry(game &game, ICharacter &enemy);
void	reward(game &game, ICharacter &enemy);
void	aftermath(game &game, ICharacter &enemy);
void	battle(ICharacter &enemy, std::string color);
void	printScreen(ICharacter &player, ICharacter &enemy);
void	retaliation(ICharacter &player, ICharacter &enemy);
void	fight(game &game, ICharacter &player, ICharacter &enemy);
void	attack(ICharacter &player, ICharacter &enemy, std::string &input);
void	opponentsTurn(ICharacter &player, ICharacter &enemy, std::string &input);

#endif
