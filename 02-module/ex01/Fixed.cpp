/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:40:18 by julberna          #+#    #+#             */
/*   Updated: 2024/05/19 20:47:12 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	println(GRN << "Default constructor called for " << this->_value << ".");
}

Fixed::~Fixed(void) {
	println(RED << "Destructor called for " << this->toFloat() << ".");
}

Fixed::Fixed(Fixed const &copy) {
	println(PRP << "Copy constructor called for " << copy << ".");
	*this = copy;
}

Fixed::Fixed(int const value) {
	println(GRN << "Int constructor called for " << value << ".");
	this->setRawBits(value << this->_bits);
}

Fixed::Fixed(float const value) {
	println(GRN << "Float constructor called for " << value << ".");
	this->setRawBits(roundf(value * float(1 << this->_bits)));
}

void	Fixed::operator=(const Fixed &copy) {
	println(BLU << "Copy assignment operator called for " << copy << ".");
	this->_value = copy.getRawBits();
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int		Fixed::getRawBits(void) const {
	return (this->_value);
}

int		Fixed::toInt(void) const {
	return (int(this->_value >> this->_bits));
}

float	Fixed::toFloat(void) const {
	return (float(this->_value / float(1 << this->_bits)));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj) {
	os << (float)obj.toFloat();
	return (os);
}
