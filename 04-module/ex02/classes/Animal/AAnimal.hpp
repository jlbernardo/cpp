/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 20:31:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"


/**
 * #### Animal base class
 * It has a type attribute and a makeSound method.
 */
class AAnimal {

protected:
	std::string	_type;		// Animal type.
	std::string	_name;		// Animal name.

public:
						/**
						 * @brief Constructs a new Animal object with unknown type.
						 */
						AAnimal(void);

						/**
						 * @brief Destroys the Animal object. It is virtual to allow polymorphism.
						 */
	virtual				~AAnimal(void);

						/**
						 * @brief Constructs a new Animal object with the given type.
						 * @param type The type of the animal.
						 */
						AAnimal(std::string type);

						/**
						 * @brief Constructs a new Animal object from the copy received.
						 * @param copy The Animal to copy from.
						 */
						AAnimal(const AAnimal &copy);

						/**
						 * @brief Copies everything from the Animal received.
						 * @param copy The Animal to copy from.
						 */
	void				operator=(const AAnimal &copy);

						/**
						 * @brief Animal makes a sound. It is virtual to allow polymorphism.
						 */
	virtual void		makeSound(void) const = 0;

						/**
						 * @brief Gets the animal type.
						 * @return The type of the animal.
						 */
	const std::string	&getType(void) const;

						/**
						 * @brief Gets the animal name.
						 * @return The name of the animal.
						 */
	const std::string	&getName(void) const;


							/**
						 * @brief Thinks about a new idea.
						 * @param idea The thought.
						 */
	virtual void		think(std::string idea) = 0;

						/**
						 * @brief Prints the Brain's ideas.
						 */
	virtual void		print(void) const = 0;
};

#endif
