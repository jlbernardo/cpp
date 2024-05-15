/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:40:18 by julberna          #+#    #+#             */
/*   Updated: 2024/05/15 16:37:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	println(GRN << "Default constructor called." << DFL);
}

Fixed::~Fixed(void) {
	println(RED << "Destructor called." << DFL);
}

Fixed::Fixed(Fixed &copy) {
	println(PRP << "Copy constructor called." << DFL);
	*this = copy;
}

void	Fixed::operator=(const Fixed &copy) {
	println(BLU << "Copy assignment operator called." << DFL);
	this->_value = copy.getRawBits();
}

void	Fixed::setRawBits(int const raw) {
	println(YLW << "setRawBits member function called." << DFL);
	this->_value = raw;
}

int		Fixed::getRawBits(void) const {
	println(YLW << "getRawBits member function called." << DFL);
	return this->_value;
}
