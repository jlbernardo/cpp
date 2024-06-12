/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 13:47:25 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
	println(WHT << "     Constructor called for " << YLW << this->_type << WHT
				<< ". Its name is " << YLW << this->_name << WHT << ".");
	this->_brain = new Brain();
}

Dog::Dog(std::string name) : AAnimal("Dog") {
	println(WHT << "     Constructor called for " << YLW << this->_type << WHT
				<< ". Its name is " << YLW << this->_name << WHT << ".");
	this->_brain = new Brain();
	this->_name = name;
}

Dog::Dog(const Dog &copy) : AAnimal("Dog") {
	println(WHT << "     Copy constructor called for " << YLW << this->_type << WHT
				<< ". Its name is also " << CYN << copy._name << WHT << ".");
	*this = copy;
}

Dog::~Dog(void) {
	delete this->_brain;
	println(WHT << "     Destructor called for " << YLW << this->_type << WHT
				<< ". Good bye, " << CYN << this->_name << WHT << "!");
}

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	println(WHT << "          (ʋ ◔  ᴥ ◔)  " << YLW << "*woof*");
}

void	Dog::think(std::string idea) {
	this->_brain->think(idea);
}

void	Dog::print(void) const {
	this->_brain->print();
}
