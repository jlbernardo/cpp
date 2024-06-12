/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:37:38 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:23:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "MateriaSource.hpp"

# define	MAX_MATERIA	4
# define	PHASE1_HP	100
# define	PHASE2_HP	150
# define	PHASE3_HP	200

/**
 * #### Character class
 * Has a name, health and 4 materia slots.
 */
class Character : public ICharacter
{
private:
	std::string			_name;						//The character's name
	unsigned int		_health;					//The character's health
	AMateria			*_materia[MAX_MATERIA];		//The character's materia slots

public:
						/**
						 * @brief Constructs a new Character.
						 */
						Character(void);

						/**
						 * @brief Constructs a new Character with a name.
						 * @param name The character's name
						 */
						Character(std::string const &name);

						/**
						 * @brief Constructs a new Character identical to the one received.
						 * @param copy The character to copy from.
						 */
						Character(Character const &copy);

						/**
						 * @brief Destructs the Character.
						 */
						~Character(void);

						/**
						 * @brief Copies everything from one character to another.
						 * @param rhs The character to copy from.
						 * @return A referece to the character.
						 */
	Character			&operator=(Character const &rhs);

						/**
						 * @brief Unequips a materia from the character.
						 * @param idx The index of the materia slot to unequip.
						 */
	void				unequip(int idx);

						/**
						 * @brief Equips a materia on the first empty slot found.
						 * @param m The materia to equip.
						 */
	void				equip(AMateria *m);

						/**
						 * @brief Uses the materia of the given slot on the target.
						 * @param idx The index of the materia slot to use.
						 * @param target The target to use the materia on.
						 */
	void				use(int idx, ICharacter &target);

						/**
						 * @brief Uses the materia of the given slot on the target.
						 * @param idx The index of the materia slot to use.
						 * @param target The target to use the materia on.
						 */
	void				use(int idx, Character &target);

						/**
						 * @brief Gets the character's name.
						 * @return The character's name.
						 */
	std::string const	&getName(void) const;

						/**
						 * @brief Gets the character's health.
						 * @return The character's health.
						 */
	unsigned int const	&getHealth(void) const;

						/**
						 * @brief Gets the gem os the materia in the given slot.
						 * @param idx The index of the materia slot.
						 * @return The materia's gem.
						 */
	std::string const	getMateriaGem(int idx) const;

						/**
						 * @brief Gets the type of the materia in the given slot.
						 * @param idx The index of the materia slot.
						 * @return The materia's type.
						 */
	std::string const	getMateriaType(int idx) const;

						/**
						 * @brief Gets the materia in the given slot.
						 * @param idx The index of the materia slot.
						 * @return A pointer to the materia.
						 */
	AMateria			*getMateria(int idx) const;

						/**
						 * @brief Modifies the character's health by the given amount.
						 * @param amount The amount to modify the health by.
						 */
	void				modHealth(int amount);

						/**
						 * @brief Sets the character's health to the given amount.
						 * @param amount The amount to set the health to.
						 */
	void				setHealth(unsigned int amount);
};

#endif
