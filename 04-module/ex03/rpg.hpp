/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 16:27:16 by julberna         ###   ########.fr       */
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

# define GHIDORAH_HP	300
# define EVANORA_HP		100
# define AZRAEL_HP		80

struct game {
	bool			victory;
	ICharacter		*ghidorah;
	ICharacter		*evanora;
	ICharacter		*azrael;
	ICharacter		*me;
	IMateriaSource	*src;
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
void	rewardMessage(game &game, ICharacter &enemy, std::string &input);
void	gemReward(std::string type);
void	battleScreen(ICharacter &player, ICharacter &enemy);
void	attackMessage(ICharacter &player, ICharacter &enemy, std::string &input);
void	retaliationMessage(ICharacter &player, ICharacter &enemy, std::string &input);
void	enemyScreen(ICharacter &enemy, std::string color);
void	enemyScream(ICharacter &enemy);
void	next(void);
void	villager(void);

//Gameplay
void	battle(game &game);
void	retry(game &game, ICharacter &enemy);
void	reward(game &game, ICharacter &enemy);
void	aftermath(game &game, ICharacter &enemy);
void	retaliation(ICharacter &player, ICharacter &enemy);
void	fight(game &game, ICharacter &player, ICharacter &enemy);

//Ending
void	ending(game &game);
void	gameOver(game &game);

#endif
