/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:20:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 21:09:30 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"
# include <limits>

void	next(void);
void	testCatClass(void);
void	testDogClass(void);
void	testWrongCatClass(void);
void	testAnimalBaseClass(void);
void	testWrongAnimalClass(void);

#endif
