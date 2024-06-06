/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 17:22:02 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
	this->_brain = new Brain();
	println(WHT << "     Constructor called for " << YLW << this->_type << WHT
				<< ". Its name is " << YLW << this->_name << WHT << ".");
}

Dog::Dog(std::string name) : AAnimal("Dog") {
	this->_name = name;
	this->_brain = new Brain();
	println(WHT << "     Constructor called for " << YLW << this->_type << WHT
				<< ". Its name is " << YLW << this->_name << WHT << ".");
}

Dog::Dog(const Dog &copy) {
	println(WHT << "     Copy constructor called for " << YLW << this->_type << WHT << ".");
	*this = copy;
}

Dog::~Dog(void) {
	delete this->_brain;
	println(WHT << "     Destructor called for " << YLW << this->_type << WHT << ".");
}

void	Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_type = copy._type;
		this->_brain = copy._brain;
	}
}

void	Dog::makeSound(void) const {
	println(WHT << "          (ʋ ◔  ᴥ ◔)  " << YLW << "*woof*");
}
