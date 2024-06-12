/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:51:44 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:55:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Character.hpp"

/**
 * #### MateriaSource class, inherits from IMateriaSource.
 * It is used to learn and create new Materia.
 */
class MateriaSource : public IMateriaSource
{

private:
	AMateria		*_materia[4];			// The 4 Materia slots.

public:
					/**
					 * @brief Constructs a new MateriaSource.
					 */
					MateriaSource(void);

					/**
					 * @brief Constructs a new MateriaSource identical to the one received.
					 * @param copy The MateriaSource to copy from.
					 */
					MateriaSource(MateriaSource const &copy);

					/**
					 * @brief Destructs the MateriaSource.
					 */
					~MateriaSource(void);

					/**
					 * @brief Assigns a MateriaSource to another.
					 * @param rhs The MateriaSource to copy from.
					 * @return A reference to the MateriaSource.
					 */
	MateriaSource	&operator=(MateriaSource const &rhs);

					/**
					 * @brief Learns a new Materia.
					 * @param m The materia to learn.
					 */
	void			learnMateria(AMateria *m);

					/**
					 * @brief Forgets a Materia.
					 * @param idx The index of the materia to forget.
					 */
	void			forgetMateria(int idx);

					/**
					 * @brief Creates a new Materia.
					 * @param type The type of materia to create.
					 * @return The created materia.
					 */
	AMateria		*createMateria(std::string const &type);
};

#endif
