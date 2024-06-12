/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:26:43 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:35:32 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "general.hpp"

#include "AMateria.hpp"

/**
 * #### Character Interface class
 * It is used to create a new Character.
 * It is a "contract" class that defines the methods that a
 * derived class must implement to be considered a Character.
 */
class ICharacter
{
public:
								/**
								 * @brief Virtual destructor to allow deleting derived classes.
								 */
	virtual 					~ICharacter() {}

								/**
								 * @brief Pure virtual unequip method. Must be implemented by derived classes.
								 * @param idx The index of the materia to unequip.
								 */
	virtual void				unequip(int idx) = 0;

								/**
								 * @brief Pure virtual equip method. Must be implemented by derived classes.
								 * @param m The materia to equip.
								 */
	virtual void				equip(AMateria* m) = 0;

								/**
								 * @brief Pure virtual getName method. Must be implemented by derived classes.
								 * @return The name of the character.
								 */
	virtual std::string const	&getName(void) const = 0;

								/**
								 * @brief Pure virtual use method. Must be implemented by derived classes.
								 * @param idx The index of the materia to use.
								 * @param target The target to use the materia on.
								 */
	virtual void				use(int idx, ICharacter& target) = 0;
};

#endif
