/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:30:47 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 22:18:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

		/**
		 * @brief Generates a random class.
		 * @return Base* - A pointer to the generated class.
		 */
Base	*generate(void);

		/**
		 * @brief Identifies the class by the pointer provided.
		 * @param p - A pointer to the class.
		 */
void	identify(Base *p);

		/**
		 * @brief Identifies the class by reference.
		 * @param p - A reference to the class.
		 */
void	identify(Base &p);

#endif
