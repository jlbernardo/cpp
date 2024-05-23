/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:10:03 by julberna          #+#    #+#             */
/*   Updated: 2024/05/23 19:05:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {
}

Point::~Point(void) {
}

void Point::operator=(const Point &operand) {
	(Fixed &)this->_x = operand._x;
	(Fixed &)this->_y = operand._y;
}

float Point::getX(void) const {
	return (this->_x.toFloat());
}

float Point::getY(void) const {
	return (this->_y.toFloat());
}
