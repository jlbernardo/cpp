/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 15:20:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	println(WHT << "     Constructor called for " << YLW << this->_type << WHT << ".");
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	println(WHT << "     Copy constructor called for " << YLW << this->_type << WHT << ".");
	*this = copy;
}

Dog::~Dog(void) {
	println(WHT << "     Destructor called for " << YLW << this->_type << WHT << ".");
}

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void	Dog::makeSound(void) const {
	println(WHT << "          (ʋ ◔  ᴥ ◔)  " << YLW << "*woof*");
}
