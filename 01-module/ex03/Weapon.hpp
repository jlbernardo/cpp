/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:35:05 by julberna          #+#    #+#             */
/*   Updated: 2024/05/09 18:17:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP


// ************************************************************************** //
//                                 Libraries                                  //
// ************************************************************************** //

# include <iostream>
# include "general.hpp"


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

/**
 * #### Weapon class.
 * Has a type, a setter and a getter.
 */
class Weapon {

private:
	std::string	_type;	// Type of weapon.

public:
				/**
				 * @brief Sets the type of the weapon.
				 *
				 * @param type A string describing the type of weapon.
				 */
	void		setType(std::string type);

				/**
				 * @brief Gets the type of the weapon.
				 *
				 * @return A string describing the type of weapon.
				 */
	std::string	const getType(void) const;

				/**
				 * @brief Creates a new weapon.
				 *
				 * @param type A string describing the type of weapon.
				 */
				Weapon(std::string type = "hands");

				/**
				 * @brief Destroys the weapon. It is no longer needed.
				 */
				~Weapon(void);

};

#endif
