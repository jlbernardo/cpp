/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:26 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 15:10:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	this->_brain = new Brain();
	println(WHT << "     Constructor called for " << CYN << this->_type << WHT
				<< ". Its name is " << CYN << this->_name << WHT << ".");
}

Cat::Cat(std::string name) : Animal("Cat") {
	this->_name = name;
	this->_brain = new Brain();
	println(WHT << "     Constructor called for " << CYN << this->_type << WHT
				<< ". Its name is " << CYN << this->_name << WHT << ".");
}

Cat::Cat(const Cat &copy) : Animal("Cat") {
	println(WHT << "     Copy constructor called for " << CYN << this->_type << WHT
				<< ". Its name is also " << CYN << copy._name << WHT << ".");
	*this = copy;
}

Cat::~Cat(void) {
	println(WHT << "     Destructor called for " << CYN << this->_type << WHT
				<< ". Good bye, " << CYN << this->_name << WHT << "!");
	delete this->_brain;
}

void	Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
}

void	Cat::makeSound(void) const {
	println(WHT << "          /ᐠ - ˕ -マ  " << CYN << "*meow*");
}
