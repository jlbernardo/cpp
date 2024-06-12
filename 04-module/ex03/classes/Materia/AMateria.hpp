/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:36:47 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 15:48:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "general.hpp"

class ICharacter;
class Character;

/**
 * #### Abstract class AMateria
 * It is the base class for all other materias. Cannot be instantiated.
 * It has a type and a gem representation.
 */
class AMateria
{
protected:
	std::string			_type;	//The materia type
	std::string			_gem;	//The materia gem

public:
						/**
						 * @brief Constructs a new abstract Materia object.
						 */
						AMateria(void);

						/**
						 * @brief Destroys the abstract Materia object.
						 */
	virtual				~AMateria(void);

						/**
						 * @brief Constructs a new abstract Materia object with the given type.
						 * @param type The materia type
						 */
						AMateria(std::string const &type);

						/**
						 * @brief Constructs a new abstract Materia object with the given type and gem.
						 * @param copy The abstract Materia to copy from.
						 */
	AMateria			&operator=(const AMateria &copy);

						/**
						 * @brief Returns the materia type.
						 * @return The materia type.
						 */
	std::string const	&getType(void) const;

						/**
						 * @brief Returns the materia gem.
						 * @return The materia gem.
						 */
	std::string const	&getGem(void) const;

						/**
						 * @brief Returns a copy of the materia. Pure virtual function, must be implemented in derived classes.
						 * @return A copy of the materia.
						 */
	virtual AMateria*	clone(void) const = 0;

						/**
						 * @brief Uses the materia on the target.
						 * @param target The target to use the materia on.
						 */
	virtual void		use(ICharacter &target);

						/**
						 * @brief Uses the materia on the target.
						 * @param target The target to use the materia on.
						 */
	virtual void		use(Character &target);
};

#endif
