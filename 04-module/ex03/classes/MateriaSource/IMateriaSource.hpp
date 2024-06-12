/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:09:20 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:34:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

/**
 * #### Interface for the MateriaSource class.
 * It is used to learn and create new Materia.
 * It is a "contract" class that defines the methods that a
 * derived class must implement to be considered a Character.
 */
class IMateriaSource
{
public:
						/**
						 * @brief Virtual destructor to allow deleting derived classes.
						 */
	virtual				~IMateriaSource() {}

						/**
						 * @brief Pure virtual learnMateria method. Must be implemented by derived classes.
						 * @param m The materia to learn.
						 */
	virtual void		learnMateria(AMateria*) = 0;

						/**
						 * @brief Pure virtual createMateria method. Must be implemented by derived classes.
						 * @param type The type of materia to create.
						 * @return The created materia.
						 */
	virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
