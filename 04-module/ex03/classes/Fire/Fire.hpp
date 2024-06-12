/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:27:41 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIRE_HPP
# define FIRE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

/**
 * #### Fire Materia, inherits from AMateria.
 * It can be used to cast a fire ball in a target's direction, dealing 5-25 damage.
 */
class Fire : public AMateria {

public:
				/**
				 * @brief Constructs a new Fire Materia.
				 */
				Fire(void);

				/**
				 * @brief Constructs a new Fire Materia identical to the one received.
				 * @param copy The Fire to copy from.
				 */
				Fire(Fire const &copy);

				/**
				 * @brief Destructs the Fire Materia.
				 */
	virtual 	~Fire(void);

				/**
				 * @brief Assigns a Fire Materia to another.
				 * @param rhs The Fire Materia to copy from.
				 * @return A reference to the Materia.
				 */
	Fire		&operator=(Fire const &other);

				/**
				 * @brief Clones the Fire Materia.
				 * @return The cloned Fire Materia.
				 */
	AMateria	*clone(void) const;

				/**
				 * @brief Uses the Fire Materia on a target.
				 * @param target The target to use Fire on.
				 */
	void		use(ICharacter &target);

				/**
				 * @brief Uses the Fire Materia on a target.
				 * @param target The target to use Fire on.
				 */
	void		use(Character &target);
};

#endif
