/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:58:26 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 15:21:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat") {
	println(WHT << "     Constructor called for " << CYN << this->_type << WHT << ".");
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	println(WHT << "     Copy constructor called for " << CYN << this->_type << WHT << ".");
	*this = copy;
}

WrongCat::~WrongCat(void) {
	println(WHT << "     Destructor called for " << CYN << this->_type << WHT << ".");
}

WrongCat	&WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	println(WHT << "          /ᐠ - ˕ -マ  " << CYN << "*quack?*");
}
