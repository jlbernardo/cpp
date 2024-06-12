/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 15:21:01 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Ditto") {
	println(WHT << "     Wrong animal constructor called for " << GRN << this->_type << WHT << ".");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	println(WHT << "     Wrong animal constructor called for " << GRN << this->_type << WHT << ".");
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	println(WHT << "     Wrong animal copy constructor called for " << GRN << this->_type << WHT << ".");
	*this = copy;
}

WrongAnimal::~WrongAnimal(void) {
	println(WHT << "     Wrong animal destructor called for " << GRN << this->_type << WHT << ".");
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	println(PRP << "          ( ☉ ‿ ⚆) *wrong wrong*");
}

const std::string	&WrongAnimal::getType(void) const {
	return (this->_type);
}
