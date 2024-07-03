/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:13:12 by julberna          #+#    #+#             */
/*   Updated: 2024/07/02 23:45:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	println("");
	println(WHT << "   Before swap():" << CYN << " a = " << RED << a << CYN << ", b = " << GRN << b);
	::swap( a, b );
	println(WHT << "   After  swap():" << CYN << " a = " << GRN << a << CYN << ", b = " << RED << b);
	println("");
	println(WHT << "     min(a, b) = " << RED << ::min(a, b));
	println(WHT << "     max(a, b) = " << GRN << ::max(a, b));

	next;

	std::string c = "chaine1";
	std::string d = "chaine2";

	println(WHT << "   Before swap():" << CYN << " c = " << RED << c << CYN << ", d = " << GRN << d);
	::swap( c, d );
	println(WHT << "   After  swap():" << CYN << " c = " << GRN << c << CYN << ", d = " << RED << d);
	println("");
	println(WHT << "     min(c, d) = " << RED << ::min(c, d));
	println(WHT << "     max(c, d) = " << GRN << ::max(c, d));

	next;

	double e = 24.2424;
	double f = 42.4242;

	println(WHT << "   Before swap():" << CYN << " e = " << RED << e << CYN << ", f = " << GRN << f);
	::swap( e, f );
	println(WHT << "   After  swap():" << CYN << " e = " << GRN << e << CYN << ", f = " << RED << f);
	println("");
	println(WHT << "     min(e, f) = " << RED << ::min(e, f));
	println(WHT << "     max(e, f) = " << GRN << ::max(e, f));
	println("");

}
