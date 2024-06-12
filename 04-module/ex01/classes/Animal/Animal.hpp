/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 19:56:30 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"


/**
 * #### Animal base class
 * It has a type attribute and a makeSound method.
 */
class Animal {

protected:
	std::string	_type;		// Animal type.
	std::string	_name;		// Animal name.

public:
						/**
						 * @brief Constructs a new Animal object with unknown type.
						 */
						Animal(void);

						/**
						 * @brief Destroys the Animal object. It is virtual to allow polymorphism.
						 */
	virtual				~Animal(void);

						/**
						 * @brief Constructs a new Animal object with the given type.
						 * @param type The type of the animal.
						 */
						Animal(std::string type);

						/**
						 * @brief Constructs a new Animal object from the copy received.
						 * @param copy The Animal to copy from.
						 */
						Animal(const Animal &copy);

						/**
						 * @brief Copies everything from the Animal received.
						 * @param copy The Animal to copy from.
						 */
	void				operator=(const Animal &copy);

						/**
						 * @brief Animal makes a sound. It is virtual to allow polymorphism.
						 */
	virtual void		makeSound(void) const;

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
};

#endif
