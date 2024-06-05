/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 18:03:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Unknown") {
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
	println(WHT << "     Animal destructor called for " << RED << this->_type << WHT << ".");
}

void	Animal::operator=(const Animal &copy) {
	if (this != &copy)
		this->_type = copy.getType();
}

void	Animal::makeSound(void) const {
	println(BLU << "          ( ☉ ‿ ⚆) ?");
}

const std::string	&Animal::getType(void) const {
	return (this->_type);
}
