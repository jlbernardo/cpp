/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 22:35:59 by julberna         ###   ########.fr       */
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

struct Game {
private:
	bool			_victory;
	Character		*_ghidorah;
	Character		*_evanora;
	Character		*_azrael;
	Character		*_player;
	MateriaSource	*_src;

public:
	Game();
	Game(Game const &rhs);
	Game &operator=(Game const &rhs);
	~Game();

	//Setup
	void	introduction();
	void	loadGame();
	void	getName();
	void	getType();
	void	giveGift();
	void	firstEnemyType();
	void	equipDark();

	//Messages
	void	retryMessage(std::string &input);
	void	rewardMessage(Character &enemy, std::string &input);
	void	gemReward(std::string type);
	void	battleScreen(Character &enemy);
	void	attackMessage(Character &enemy, std::string &input);
	void	retaliationMessage(Character &enemy, std::string &input);
	void	enemyScreen(Character &enemy, std::string color);
	void	enemyScream(Character &enemy);
	void	next(void);
	void	villager(void);

	//Gameplay
	void	battle();
	void	retry(Character &enemy);
	void	reward(Character &enemy);
	void	aftermath(Character &enemy);
	void	retaliation(Character &enemy);
	void	fight(Character &enemy);

	//Ending
	void	ending();
	void	gameOver();
};


#endif
