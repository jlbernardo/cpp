/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:26 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 03:02:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	// println(WHT << "     Constructor called for " << CYN << this->_type << WHT << ".");
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	// println(WHT << "     Copy constructor called for " << CYN << this->_type << WHT << ".");
	*this = copy;
}

Cat::~Cat(void) {
	// println(WHT << "     Destructor called for " << CYN << this->_type << WHT << ".");
}

Cat	&Cat::operator=(const Cat &copy) {
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	println(WHT << "          /ᐠ - ˕ -マ  " << CYN << "*meow*");
}

std::ostream	&operator<<(std::ostream &o, const Cat &rhs) {
	o << rhs.getType();
	return (o);
}
