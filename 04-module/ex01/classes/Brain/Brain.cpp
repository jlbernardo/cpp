/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:34:44 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 14:49:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	println(WHT << "     A new brain was synthesized, empty for now.");
}

Brain::~Brain(void) {
	println(WHT << "     Call the organ harvesters, we have brain death.");
}

Brain::Brain(const Brain &copy) {
	println(WHT << "     Brain cloned. It's thinking about the same things as the original.");
	*this = copy;
}

void	Brain::operator=(const Brain &copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i].assign(copy._ideas[i]);
	}
}

void	Brain::print(void) const {
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].empty())
			continue ;
		println(WHT << "     Idea " << i + 1 << ": " << GRN << this->_ideas[i]);
	}
}

void	Brain::think(std::string idea) {
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].empty()) {
			this->_ideas[i] = idea;
			println(WHT << "     Brain thinks " << GRN << this->_ideas[i]);
			return ;
		}
	}
	println(WHT << "     Brain is full of ideas. It can't think about anything else.");
}
