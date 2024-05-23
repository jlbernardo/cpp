/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:10:04 by julberna          #+#    #+#             */
/*   Updated: 2024/05/23 20:32:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/**
 * #### Point class
 * Represents a point in a 2D space.
 */
class Point {

private:
	Fixed const _x;			// x coordinate of the point
	Fixed const _y;			// y coordinate of the point

public:
			/**
			 * @brief Constructs a new Point object.
			 */
			Point(void);

			/**
			 * @brief Constructs a new Point object with given coordinates.
			 * @param x the x coordinate of the point.
			 * @param y the y coordinate of the point.
			 */
			Point(const float x, const float y);

			/**
			 * @brief Copy constructor of Point class object.
			 * @param copy the object from which to copy from.
			 */
			Point(const Point &copy);

			/**
			 * @brief Destroys the Point object.
			 */
			~Point(void);

			/**
			 * @brief Overloaded assignment operator. Copies the value from one object to the other.
			 * @param operand the object to assign.
			 */
	void	operator=(const Point &operand);

			/**
			 * @brief Gets the x coordinate of the point.
			 * @return float – the x coordinate.
			 */
	float	getX(void) const;

			/**
			 * @brief Gets the y coordinate of the point.
			 * @return float – the y coordinate.
			 */
	float	getY(void) const;
};

			/**
			 * @brief Checks if a point is inside a triangle.
			 * @param a the first vertex of the triangle.
			 * @param b the second vertex of the triangle.
			 * @param c the third vertex of the triangle.
			 * @param point the point to be checked.
			 * @return true if the point is inside the triangle; false if it's outside the triangle, on the edge or if it's a vertex.
			 */
bool		bsp( Point const a, Point const b, Point const c, Point const point);

			/**
			 * @brief Calculates the area of a triangle.
			 * @param a the first vertex of the triangle.
			 * @param b the second vertex of the triangle.
			 * @param c the third vertex of the triangle.
			 * @return float – the area of the triangle.
			 */
float		area(Point const a, Point const b, Point const c);

#endif
