/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:54:42 by julberna         ###   ########.fr       */
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

# define AZRAEL_HP		80			//Azrael's HP
# define EVANORA_HP		100			//Evanora's HP
# define GHIDORAH_HP	300			//Ghidorah's HP

struct Game {
private:
	bool			_victory;		//Determines if the current battle was won or not.
	Character		*_ghidorah;		//The final boss.
	Character		*_evanora;		//The second enemy.
	Character		*_azrael;		//The first enemy.
	Character		*_player;		//This is you.
	MateriaSource	*_src;			//The source of Materia, from where we learn new Materia.

protected:
					/**
					 * @brief Constructs a the Game instance. It is a singleton, that's why its constructor is protected.
					 */
					Game(void);

					/**
					 * @brief Constructs a new Game instance identical to the one received. Protected so it can't be called.
					 * @param copy The Game to copy from.
					 */
					Game(Game const &rhs);

					/**
					 * @brief Assigns a Game instance to another. Protected so it can't be called.
					 * @param rhs The Game to copy from.
					 * @return A reference to the Game.
					 */
	Game 			&operator=(Game const &rhs);

public:
					/**
					 * @brief Destructs the Game instance.
					 */
					~Game(void);

					/**
					 * @brief Gets the Game instance. Since it's a singleton, this is the only way to instantiate it.
					 * @return The Game instance.
					 */
	static Game		&getInstance(void);

					/**
					 * @brief Runs the game.
					 */
	void			run(void);

	//Setup
					/**
					 * @brief Prompts the player for their name.
					 */
	void			getName(void);

					/**
					 * @brief Prompts the player for their magic type.
					 */
	void			getType(void);

					/**
					 * @brief Initializes all of the game assets.
					 */
	void			loadGame(void);

					/**
					 * @brief Gives the player a Cure Materia.
					 */
	void			giveGift(void);

					/**
					 * @brief Equips Dark Materia on the MateriaSource slots and equips it on the last boss.
					 */
	void			equipDark(void);

					/**
					 * @brief Determines the first enemy magic type based on the player's magic type.
					 */
	void			firstEnemyType(void);

	//Messages
					/**
					 * @brief Displays "Press enter to continue" message.
					 */
	void			next(void);

					/**
					 * @brief Displays villager character.
					 */
	void			villager(void);

					/**
					 * @brief Displays the gem reward line on the reward screen.
					 */
	void			gemReward(std::string type);

					/**
					 * @brief Displays the enemy's scream line.
					 */
	void			enemyScream(Character &enemy);

					/**
					 * @brief Displays the battleground.
					 */
	void			battleScreen(Character &enemy);

					/**
					 * @brief Displays the retry message and increses player's HP if they choose to retry.
					 */
	void			retryMessage(std::string &input);

					/**
					 * @brief Displays the characters on the battleground.
					 */
	void			enemyScreen(Character &enemy, std::string color);

					/**
					 * @brief Prompts the player for their magic slot choice.
					 */
	void			attackMessage(Character &enemy, std::string &input);

					/**
					 * @brief Displays the reward message.
					 */
	void			rewardMessage(Character &enemy, std::string &input);

					/**
					 * @brief Displays enemy's turn confirmation.
					 */
	void			retaliationMessage(Character &enemy, std::string &input);

	//Gameplay
					/**
					 * @brief Runs the battle sequence.
					 */
	void			battle(void);

					/**
					 * @brief Resets stats if player chooses to retry or exits the game if not.
					 */
	void			retry(Character &enemy);

					/**
					 * @brief Fight logic depending on player input.
					 */
	void			fight(Character &enemy);

					/**
					 * @brief Rewards the player with a Materia and increases their HP.
					 */
	void			reward(Character &enemy);

					/**
					 * @brief Checks if retry or reward messages should be displayed.
					 */
	void			aftermath(Character &enemy);

					/**
					 * @brief Retaliates against the player. It's the enemy's turn.
					 */
	void			retaliation(Character &enemy);

	//Ending
					/**
					 * @brief Displays the ending screen.
					 */
	void			ending(void);

					/**
					 * @brief Deletes all the game assets.
					 */
	void			gameOver(void);
};


#endif
