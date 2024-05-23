/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:00 by julberna          #+#    #+#             */
/*   Updated: 2024/05/23 20:17:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (area(a, b, point) == 0 || area(b, c, point) == 0 || area(a, c, point) == 0)
		return (false);
	return (area(a, b, c) == area(a, b, point) + area(b, c, point) + area(a, c, point));
}

float	area(Point const a, Point const b, Point const c) {
	return (std::abs(a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY())));
}
