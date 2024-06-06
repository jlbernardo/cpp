/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:20:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 16:50:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include <limits>
# include <string>
# include "Cat.hpp"
# include "Dog.hpp"
# include <iostream>
# include "WrongCat.hpp"

		/**
		 * @brief Clears the screen and displays the next test.
		 */
void	next(void);

		/**
		 * @brief Tests the Cat class, now with a brain.
		 */
void	testBrainyCat(void);

		/**
		 * @brief Tests the Dog class, now with a brain.
		 */
void	testBrainyDog(void);

		/**
		 * @brief Tests the the cloning of an animal.
		 */
void	testCloning(void);

		/**
		 * @brief Tests an array of mixed animals, as requested by the PDF.
		 */
void	testAnimalArray(void);

#endif
