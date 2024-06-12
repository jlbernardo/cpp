/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dark.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:22 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:25:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DARK_HPP
# define DARK_HPP

# include "AMateria.hpp"
# include "Character.hpp"

/**
 * #### Dark Materia, inherits from AMateria.
 * It can be used to suck life out of a Character by 30-50 HP.
 */
class Dark : public AMateria {

public:
				/**
				 * @brief Constructs a new Dark Materia.
				 */
				Dark(void);

				/**
				 * @brief Constructs a new Dark Materia identical to the one received.
				 * @param copy The Dark to copy from.
				 */
				Dark(Dark const &copy);

				/**
				 * @brief Destructs the Dark Materia.
				 */
	virtual 	~Dark(void);

				/**
				 * @brief Assigns a Dark to another.
				 * @param rhs The Dark to copy from.
				 * @return A reference to the Materia.
				 */
	Dark		&operator=(Dark const &rhs);

				/**
				 * @brief Clones the Dark Materia.
				 * @return The cloned Dark Materia.
				 */
	AMateria	*clone(void) const;

				/**
				 * @brief Uses the Dark Materia on a target.
				 * @param target The target to use Dark on.
				 */
	void		use(ICharacter &target);

				/**
				 * @brief Uses the Dark Materia on a target.
				 * @param target The target to use Dark on.
				 */
	void		use(Character &target);
};

#endif
