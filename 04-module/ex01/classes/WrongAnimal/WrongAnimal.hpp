/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:51:24 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "general.hpp"

/**
 * #### WrongAnimal base class
 * It has a type attribute and a makeSound method (not virtual).
 */
class WrongAnimal {

protected:
	std::string	_type;

public:
						/**
						 * @brief Constructs a new WrongAnimal object with unknown type.
						 */
						WrongAnimal(void);

						/**
						 * @brief Destroys the WrongAnimal object.
						 */
	virtual				~WrongAnimal(void);

						/**
						 * @brief Constructs a new WrongAnimal object with the given type.
						 * @param type The type of the animal.
						 */
						WrongAnimal(std::string type);

						/**
						 * @brief Constructs a new WrongAnimal object from the copy received.
						 * @param copy The WrongAnimal to copy from.
						 */
						WrongAnimal(const WrongAnimal &copy);

						/**
						 * @brief Copies everything from the WrongAnimal received.
						 * @param copy The WrongAnimal to copy from.
						 */
	WrongAnimal			&operator=(const WrongAnimal &copy);

						/**
						 * @brief Animal makes a sound. It is not virtual, so derived classes cannot override it.
						 */
	void				makeSound(void) const;

						/**
						 * @brief Returns the type of the WrongAnimal.
						 * @return The type of the WrongAnimal.
						 */
	const std::string	&getType(void) const;
};

#endif
