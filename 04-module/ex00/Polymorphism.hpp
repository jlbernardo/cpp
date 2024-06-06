/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:20:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 21:37:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"
# include <limits>

		/**
		 * @brief Clears the screen and displays the next test.
		 */
void	next(void);

		/**
		 * @brief Tests the Cat class.
		 */
void	testCatClass(void);

		/**
		 * @brief Tests the Dog class.
		 */
void	testDogClass(void);

		/**
		 * @brief Tests the WrongCat class.
		 */
void	testWrongCatClass(void);

		/**
		 * @brief Tests the Animal base class.
		 */
void	testAnimalBaseClass(void);

		/**
		 * @brief Tests the Wrong Animal base class.
		 */
void	testWrongAnimalClass(void);

#endif
