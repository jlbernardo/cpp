/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:23:32 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 17:33:44 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

/**
 * #### Cat class, derived from abstract Animal
 * It overrides the makeSound method to make a cat sound
 */
class Cat : public AAnimal {

public:
				/**
				 * @brief Constructs a new Cat object.
				 */
				Cat(void);

				/**
				 * @brief Destroys the Cat object.
				 */
				~Cat(void);

				/**
				 * @brief Constructs a new Cat object with the given name.
				 * @param name The name of the cat.
				 */
				Cat(std::string name);

				/**
				 * @brief Constructs a new Cat object from the copy received.
				 * @param copy The Cat to copy from.
				 */
				Cat(const Cat &copy);

				/**
				 * @brief Copies everything from the Cat received.
				 * @param copy The Cat to copy from.
				 */
	void		operator=(const Cat &copy);

				/**
				 * @brief It meows.
				 */
	void		makeSound(void) const;

};

#endif
