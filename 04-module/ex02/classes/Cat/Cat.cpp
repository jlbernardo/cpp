/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:26 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:47:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
	println(WHT << "     Constructor called for " << CYN << this->_type << WHT
				<< ". Its name is " << CYN << this->_name << WHT << ".");
	this->_brain = new Brain();
}

Cat::Cat(std::string name) : AAnimal("Cat") {
	println(WHT << "     Constructor called for " << CYN << this->_type << WHT
				<< ". Its name is " << CYN << this->_name << WHT << ".");
	this->_brain = new Brain();
	this->_name = name;
}

Cat::Cat(const Cat &copy) : AAnimal("Cat") {
	println(WHT << "     Copy constructor called for " << CYN << this->_type << WHT
				<< ". Its name is also " << CYN << copy._name << WHT << ".");
	*this = copy;
}

Cat::~Cat(void) {
	delete this->_brain;
	println(WHT << "     Destructor called for " << CYN << this->_type << WHT
				<< ". Good bye, " << CYN << this->_name << WHT << "!");
}

Cat	&Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	println(WHT << "          /ᐠ - ˕ -マ  " << CYN << "*meow*");
}

void	Cat::think(std::string idea) {
	this->_brain->think(idea);
}

void	Cat::print(void) const {
	this->_brain->print();
}
