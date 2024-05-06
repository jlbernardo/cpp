/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:51:49 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 22:31:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include "colors.hpp"

/**
 * Inserts content into the std::cout and adds a new line at the end.
 */
# define println(x) std::cout << x << std::endl;


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * #### It was a human once.
 * Has a name and can announce itself.
 */
class Zombie {

private:
	std::string	_name;	// The name of the zombie.

public:
	/**
	 * Announces the zombie.
	 */
	void	announce(void);

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
 * @brief Creates a new zombie.
 * @param name The name of the zombie.
 * @return A pointer to the new zombie.
 */
Zombie	*newZombie(std::string name);

/**
 * @brief Creates a random zombie.
 * @param name The name of the zombie.
 */
void	randomChump(std::string name);

#endif
