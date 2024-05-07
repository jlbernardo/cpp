/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:38:27 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:31:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include "general.hpp"
# include "Weapon.hpp"

// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * #### Human of class A.
 * Has a name and a weapon, for sure.
 */
class HumanA {

private:
	std::string	_name;				// Name of the human.
	Weapon		&_weapon;			// Weapon of the human. It is a reference.

public:

				/**
				 * @brief The human attacks with the weapon they're holding.
				 */
	void		attack(void);

				/**
				 * @brief Gives birth to a new Human of Class A.
				 *
				 * @param name Name of the human.
				 * @param weapon Weapon they hold.
				 */
				HumanA(std::string name, Weapon &weapon);

				/**
				 * @brief Kills the human. Poor thing.
				 */
				~HumanA(void);

};

#endif
