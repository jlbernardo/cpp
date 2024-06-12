/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:34:46 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 20:06:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "general.hpp"

/**
 * #### Brain class
 * It has space for 100 ideas.
 */
class Brain {

private:
	std::string	_ideas[100];	// Brain's ideas.

public:

				/**
				 * @brief Constructs a new Brain object.
				 */
				Brain(void);

				/**
				 * @brief Destroys the Brain object.
				 */
				~Brain(void);

				/**
				 * @brief Creates a new Brain, identical to the copy provided.
				 * @param copy The Brain to copy from.
				 */
				Brain(const Brain &copy);

				/**
				 * @brief Assigns the ideas from one Brain to the other.
				 * @param copy The Brain to copy from.
				 * @return The Brain with the new ideas.
				 */
	void		operator=(const Brain &copy);

				/**
				 * @brief Prints the Brain's ideas.
				 */
	void		print(void) const;

				/**
				 * @brief Thinks about a new idea.
				 * @param idea The thought.
				 */
	void		think(std::string idea);
};

#endif
