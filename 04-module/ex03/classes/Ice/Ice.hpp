/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:28:45 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

/**
 * #### Ice Materia, inherits from AMateria.
 * It can be used to cast an ice bolt in a target's direction, dealing 10-20 damage.
 */
class Ice : public AMateria {

public:
				/**
				 * @brief Constructs a new Ice Materia.
				 */
				Ice(void);

				/**
				 * @brief Constructs a new Ice Materia identical to the one received.
				 * @param copy The Ice to copy from.
				 */
				Ice(Ice const &copy);

				/**
				 * @brief Destructs the Ice Materia.
				 */
	virtual 	~Ice(void);

				/**
				 * @brief Assigns an Ice Materia to another.
				 * @param rhs The Ice Materia to copy from.
				 * @return A reference to the Materia.
				 */
	Ice			&operator=(Ice const &rhs);

				/**
				 * @brief Clones the Ice Materia.
				 * @return The cloned Ice Materia.
				 */
	AMateria	*clone(void) const;

				/**
				 * @brief Uses the Ice Materia on a target.
				 * @param target The target to use Ice on.
				 */
	void		use(ICharacter &target);

				/**
				 * @brief Uses the Ice Materia on a target.
				 * @param target The target to use Ice on.
				 */
	void		use(Character &target);
};

#endif
