/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:27:57 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 17:33:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

/**
 * #### Dog class, derived from abstract Animal
 * It overrides the makeSound method to make a dog sound
 */
class Dog : public AAnimal {

public:
				/**
				 * @brief Constructs a new Dog object.
				 */
				Dog(void);

				/**
				 * @brief Destroys the Dog object.
				 */
				~Dog(void);

				/**
				 * @brief Constructs a new Dog object with the given name.
				 * @param name The name of the dog.
				 */
				Dog(std::string name);

				/**
				 * @brief Constructs a new Dog object from the copy received.
				 * @param copy The Dog to copy from.
				 */
				Dog(const Dog &copy);

				/**
				 * @brief Copies everything from the Dog received.
				 * @param copy The Dog to copy from.
				 */
	void		operator=(const Dog &copy);

				/**
				 * @brief It barks.
				 */
	void		makeSound(void) const;
};

#endif
