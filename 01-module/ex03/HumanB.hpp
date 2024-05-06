/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:38:29 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 22:55:16 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include "colors.hpp"
# include "Weapon.hpp"

// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * #### Human of class B.
 * Has a name and a weapon. Maybe. Who knows?
 */
class HumanB {

private:
	std::string	_name;				// Name of the human.
	Weapon		*_weapon;			// Weapon of the human. It is a pointer.

public:

				/**
				 * @brief The human attacks with whatever weapon they're holding.
				 */
	void		attack(void);

				/**
				 * @brief Arms the human.
				 *
				 * @param weapon The weapon they hold.
				 */
	void		setWeapon(Weapon &weapon);

				/**
				 * @brief Gives birth to a new Human of Class B.
				 *
				 * @param name Name of the human.
				 */
				HumanB(std::string name);

				/**
				 * @brief Kills the human. It had to go...
				 */
				~HumanB(void);

};

#endif
