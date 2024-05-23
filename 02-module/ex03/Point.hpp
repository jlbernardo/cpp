/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:10:04 by julberna          #+#    #+#             */
/*   Updated: 2024/05/23 19:59:17 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

/**
 * #### Point class
 * Represents a point in a 2D space.
 */
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
			 * @brief Assignation operator overload.
			 * @param operand the object to assign.
			 */
	void	operator=(const Point &operand);

			/**
			 * @brief Get the x coordinate of the point.
			 * @return the x coordinate of the point.
			 */
	float	getX(void) const;

			/**
			 * @brief Get the y coordinate of the point.
			 * @return the y coordinate of the point.
			 */
	float	getY(void) const;
};

			/**
			 * @brief Check if a point is inside a triangle.
			 * @param a the first point of the triangle.
			 * @param b the second point of the triangle.
			 * @param c the third point of the triangle.
			 * @param point the point to check.
			 * @return true if the point is inside the triangle, false otherwise.
			 */
bool		bsp( Point const a, Point const b, Point const c, Point const point);

			/**
			 * @brief Calculate the area of a triangle.
			 * @param a the first point of the triangle.
			 * @param b the second point of the triangle.
			 * @param c the third point of the triangle.
			 * @return the area of the triangle.
			 */
float		area(Point const a, Point const b, Point const c);

#endif
