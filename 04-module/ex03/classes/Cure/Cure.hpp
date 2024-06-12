/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:22 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:23:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

/**
 * #### Cure Materia, inherits from AMateria.
 * It can be used to heal a Character by 10-20 HP.
 */
class Cure : public AMateria {

public:
				/**
				 * @brief Constructs a new Cure Materia.
				 */
				Cure(void);

				/**
				 * @brief Constructs a new Cure Materia identical to the one received.
				 * @param copy The Cure to copy from.
				 */
				Cure(Cure const &copy);

				/**
				 * @brief Destructs the Cure Materia.
				 */
	virtual 	~Cure(void);

				/**
				 * @brief Assigns a Cure to another.
				 * @param rhs The Cure to copy from.
				 * @return A reference to the Cure.
				 */
	Cure		&operator=(Cure const &rhs);

				/**
				 * @brief Clones the Cure Materia.
				 * @return The cloned Cure.
				 */
	AMateria	*clone(void) const;

				/**
				 * @brief Uses the Cure Materia on a target.
				 * @param target The target to use the Cure on.
				 */
	void		use(ICharacter &target);

				/**
				 * @brief Uses the Cure Materia on a target.
				 * @param target The target to use the Cure on.
				 */
	void		use(Character &target);
};

#endif
