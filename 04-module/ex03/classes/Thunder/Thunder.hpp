/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:32:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef THUNDER_HPP
# define THUNDER_HPP

# include "AMateria.hpp"
# include "Character.hpp"

/**
 * #### Thunder Materia, inherits from AMateria.
 * It can be used to cast a thunder bolt in a target's direction, dealing 20-40 damage.
 */
class Thunder : public AMateria {

public:
				/**
				 * @brief Constructs a new Thunder Materia.
				 */
				Thunder(void);

				/**
				 * @brief Constructs a new Thunder Materia identical to the one received.
				 * @param copy The Thunder to copy from.
				 */
				Thunder(Thunder const &copy);

				/**
				 * @brief Destructs the Thunder Materia.
				 */
	virtual 	~Thunder(void);

				/**
				 * @brief Assigns a Thunder Materia to another.
				 * @param rhs The Thunder Materia to copy from.
				 * @return A reference to the Materia.
				 */
	Thunder		&operator=(Thunder const &rhs);

				/**
				 * @brief Clones the Thunder Materia.
				 * @return The cloned Thunder Materia.
				 */
	AMateria	*clone(void) const;

				/**
				 * @brief Uses the Thunder Materia on a target.
				 * @param target The target to use Thunder on.
				 */
	void		use(ICharacter &target);

				/**
				 * @brief Uses the Thunder Materia on a target.
				 * @param target The target to use Thunder on.
				 */
	void		use(Character &target);
};

#endif
