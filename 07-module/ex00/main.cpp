/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:13:12 by julberna          #+#    #+#             */
/*   Updated: 2024/07/04 15:05:18 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Fixed.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	println(WHT << "\n Exploring templates, we have 3 functions: " << YLW << "swap" <<
			WHT << ", " << RED << "min" << WHT <<" and " << GRN << "max" << WHT << ".");
	println(WHT << " They can be used with any type, for example, with integers:\n");
	println(WHT << "   Before swap(): a = " << RED << a << WHT << ", b = " << GRN << b);
	::swap( a, b );
	println(WHT << "    After swap(): a = " << GRN << a << WHT << ", b = " << RED << b);
	println("");
	println(WHT << "     min(a, b) = " << RED << ::min(a, b));
	println(WHT << "     max(a, b) = " << GRN << ::max(a, b));

	next;

	std::string c = "chaine1";
	std::string d = "chaine2";

	println(WHT << "\n With strings:\n");
	println(WHT << "   Before swap(): c = " << RED << c << WHT << ", d = " << GRN << d);
	::swap( c, d );
	println(WHT << "    After swap(): c = " << GRN << c << WHT << ", d = " << RED << d);
	println("");
	println(WHT << "     min(c, d) = " << RED << ::min(c, d));
	println(WHT << "     max(c, d) = " << GRN << ::max(c, d));

	next;

	double e = 24.2424;
	double f = 42.4242;

	println(WHT << "\n Or with doubles:\n");
	println(WHT << "   Before swap(): e = " << RED << e << WHT << ", f = " << GRN << f);
	::swap( e, f );
	println(WHT << "    After swap(): e = " << GRN << e << WHT << ", f = " << RED << f);
	println("");
	println(WHT << "     min(e, f) = " << RED << ::min(e, f));
	println(WHT << "     max(e, f) = " << GRN << ::max(e, f));
	println("");

	next;

	Fixed g = 22.22f;
	Fixed h = 44.44f;

	println(WHT << "\n And even with the Fixed point class we created on a previous list:\n");
	println(WHT << "   Before swap(): g = " << RED << g << WHT << ", h = " << GRN << h);
	::swap( g, h );
	println(WHT << "    After swap(): g = " << GRN << g << WHT << ", h = " << RED << f);
	println("");
	println(WHT << "     min(g, h) = " << RED << ::min(g, h));
	println(WHT << "     max(g, h) = " << GRN << ::max(g, h));
	println("");
}
