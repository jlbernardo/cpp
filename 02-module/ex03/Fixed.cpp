/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:40:18 by julberna          #+#    #+#             */
/*   Updated: 2024/05/24 15:44:58 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

Fixed::Fixed(int const value) {
	this->setRawBits(value << this->_bits);
}

Fixed::Fixed(float const value) {
	this->setRawBits(roundf(value * float(1 << this->_bits)));
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {
	return (this->_value);
}

int Fixed::toInt(void) const
{
	return (int(this->_value >> this->_bits));
}

float Fixed::toFloat(void) const {
	return (float(this->_value / float(1 << this->_bits)));
}

std::ostream &operator<<(std::ostream &os, Fixed const &obj) {
	os << (float)obj.toFloat();
	return (os);
}

void Fixed::operator=(const Fixed &copy) {
	this->_value = copy.getRawBits();
}

bool Fixed::operator>(const Fixed &operand) {
	if (this->getRawBits() > operand.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &operand) {
	if (this->getRawBits() < operand.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &operand) {
	if (this->getRawBits() >= operand.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &operand) {
	if (this->getRawBits() <= operand.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &operand) {
	if (this->getRawBits() == operand.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &operand) {
	if (this->getRawBits() != operand.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &operand) {
	return (Fixed(this->toFloat() + operand.toFloat()));
}

Fixed Fixed::operator-(const Fixed &operand) {
	return (Fixed(this->toFloat() - operand.toFloat()));
}

Fixed Fixed::operator*(const Fixed &operand) {
	return (Fixed(this->toFloat() * operand.toFloat()));
}

Fixed Fixed::operator/(const Fixed &operand) {
	return (Fixed(this->toFloat() / operand.toFloat()));
}

Fixed &Fixed::operator++(void) {
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	temp(this->toFloat());

	this->_value++;
	return (temp);
}

Fixed &Fixed::operator--(void) {
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	temp(this->toFloat());

	this->_value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &one, Fixed &two) {
	if (one < two)
		return (one);
	return (two);
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two) {
	if (one.getRawBits() < two.getRawBits())
		return (one);
	return (two);
}

Fixed &Fixed::max(Fixed &one, Fixed &two) {
	if (one > two)
		return (one);
	return (two);
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two) {
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
}
