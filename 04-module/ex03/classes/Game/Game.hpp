/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:38:20 by julberna         ###   ########.fr       */
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

# define AZRAEL_HP		80
# define EVANORA_HP		100
# define GHIDORAH_HP	300

struct Game {
private:
	bool			_victory;
	Character		*_ghidorah;
	Character		*_evanora;
	Character		*_azrael;
	Character		*_player;
	MateriaSource	*_src;

protected:
					Game();
					Game(Game const &rhs);
	Game 			&operator=(Game const &rhs);

public:
					~Game();
	static Game		&getInstance();
	void			run();

	//Setup
	void			getName();
	void			getType();
	void			loadGame();
	void			giveGift();
	void			equipDark();
	void			firstEnemyType();

	//Messages
	void			next(void);
	void			villager(void);
	void			gemReward(std::string type);
	void			enemyScream(Character &enemy);
	void			battleScreen(Character &enemy);
	void			retryMessage(std::string &input);
	void			enemyScreen(Character &enemy, std::string color);
	void			attackMessage(Character &enemy, std::string &input);
	void			rewardMessage(Character &enemy, std::string &input);
	void			retaliationMessage(Character &enemy, std::string &input);

	//Gameplay
	void			battle();
	void			retry(Character &enemy);
	void			fight(Character &enemy);
	void			reward(Character &enemy);
	void			aftermath(Character &enemy);
	void			retaliation(Character &enemy);

	//Ending
	void			ending();
	void			gameOver();
};


#endif
