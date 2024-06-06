/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 17:26:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Ditto"), _name("Unknown") {
	println(WHT << "     Animal constructor called for " << GRN << this->_type << WHT << ".");
}

AAnimal::AAnimal(std::string type) : _type(type), _name("Unknown") {
	println(WHT << "     Animal constructor called for " << GRN << this->_type << WHT << ".");
}

AAnimal::AAnimal(const AAnimal &copy) {
	println(WHT << "     Animal copy constructor called for " << GRN << this->_type << WHT << ".");
	*this = copy;
}

AAnimal::~AAnimal(void) {
	println(WHT << "     Animal destructor called for " << GRN << this->_type << WHT << ".");
}

void	AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy)
		this->_type = copy.getType();
}

const std::string	&AAnimal::getType(void) const {
	return (this->_type);
}

const std::string	&AAnimal::getName(void) const {
	return (this->_name);
}

Brain			&AAnimal::getBrain(void) const {
	return (*this->_brain);
}
