/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:27:57 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:55:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/**
 * #### Dog class, derived from Animal
 * It overrides the makeSound method to make a dog sound
 */
class Dog : public Animal {

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
				 * @brief Constructs a new Dog object from the copy received.
				 * @param copy The Dog to copy from.
				 */
				Dog(const Dog &copy);

				/**
				 * @brief Copies everything from the Dog received.
				 * @param copy The Dog to copy from.
				 */
	Dog			&operator=(const Dog &copy);

				/**
				 * @brief It barks.
				 */
	void		makeSound(void) const;
};

#endif
