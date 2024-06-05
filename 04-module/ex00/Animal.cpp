/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 18:45:44 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Ditto") {
	println(WHT << "     Animal constructor called for " << GRN << this->_type << WHT << ".");
}

Animal::Animal(std::string type) : _type(type) {
	println(WHT << "     Animal constructor called for " << GRN << this->_type << WHT << ".");
}

Animal::Animal(const Animal &copy) {
	println(WHT << "     Animal copy constructor called for " << GRN << this->_type << WHT << ".");
	*this = copy;
}

Animal::~Animal(void) {
	println(WHT << "     Animal destructor called for " << GRN << this->_type << WHT << ".");
}

void	Animal::operator=(const Animal &copy) {
	if (this != &copy)
		this->_type = copy.getType();
}

void	Animal::makeSound(void) const {
	println(PRP << "          ( ☉ ‿ ⚆) ?");
}

const std::string	&Animal::getType(void) const {
	return (this->_type);
}
