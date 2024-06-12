/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 21:58:49 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPG_HPP
# define RPG_HPP

# include "Character.hpp"
# include "AMateria.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "Fire.hpp"
# include "Dark.hpp"
# include "Thunder.hpp"
# include "general.hpp"
# include <limits>
# include <string>
# include <iomanip>

# define GHIDORAH_HP	300
# define EVANORA_HP		100
# define AZRAEL_HP		80

struct game {
	bool			victory;
	Character		*ghidorah;
	Character		*evanora;
	Character		*azrael;
	Character		*me;
	MateriaSource	*src;
};

//Setup
void	introduction(game &game);
void	loadGame(game &game);
void	getName(game &game);
void	getType(game &game);
void	giveGift(game &game);
void	firstEnemyType(game &game);
void	equipDark(game &game);

//Messages
void	retryMessage(game &game, std::string &input);
void	rewardMessage(game &game, Character &enemy, std::string &input);
void	gemReward(std::string type);
void	battleScreen(Character &player, Character &enemy);
void	attackMessage(Character &player, Character &enemy, std::string &input);
void	retaliationMessage(Character &player, Character &enemy, std::string &input);
void	enemyScreen(Character &enemy, std::string color);
void	enemyScream(Character &enemy);
void	next(void);
void	villager(void);

//Gameplay
void	battle(game &game);
void	retry(game &game, Character &enemy);
void	reward(game &game, Character &enemy);
void	aftermath(game &game, Character &enemy);
void	retaliation(Character &player, Character &enemy);
void	fight(game &game, Character &player, Character &enemy);

//Ending
void	ending(game &game);
void	gameOver(game &game);

#endif
