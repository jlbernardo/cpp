/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:51:49 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:31:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include "general.hpp"

/**
 * Inserts content into the std::cout and adds a new line at the end.
 */
# define println(x) std::cout << x << std::endl;


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * #### It was a human once.
 * Has a name, can announce itself and has a function to set the name to a new value.
 */
class Zombie {

private:
	std::string	_name;	// The name of the zombie.

public:
	/**
	 * @brief Announces the zombie.
	 */
	void	announce(void);

	/**
	 * @brief Sets the name of the zombie.
	 * @param name The new name of the zombie.
	 */
	void	setName(std::string name);

	/**
	 * @brief Constructor of the Zombie class.
	 * @param name The name of the zombie.
	 */
	Zombie	(std::string name = "Unknown");

	/**
	 * @brief Destructor of the Zombie class.
	 */
	~Zombie	(void);

};


// ************************************************************************** //
//                             General Functions                              //
// ************************************************************************** //

/**
 * @brief Creates a horde of zombies.
 * @param N The number of zombies in the horde.
 * @param name The name of the zombies.
 * @return A pointer to the first zombie of the horde.
 */
Zombie	*zombieHorde(int N, std::string name);

#endif
