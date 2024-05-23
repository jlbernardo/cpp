/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:35:40 by julberna          #+#    #+#             */
/*   Updated: 2024/05/23 20:26:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {

	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point P1(10, 0);
	Point P2(10, 15);
	Point P3(30, 15);

	println(WHT << "\n  Let's consider the following coordinates:");
	println("");
	println(WHT << "                   P1  ");
	println(WHT << "                 (10,0) ");
	println(WHT << "    A(0,0) 🮢─ ─ ─ ─ ─ ─ ─ ─🮣 C(20,0)");
	println(WHT << "            🮢             🮣");
	println(WHT << "             🮢           🮣");
	println(WHT << "              🮢    P2   🮣             P3");
	println(WHT << "               🮢(10,15)🮣            (30,15)");
	println(WHT << "                🮢     🮣");
	println(WHT << "                 🮢   🮣");
	println(WHT << "                  🮢 🮣");
	println(WHT << "                   🮦");
	println(WHT << "               B(10,30)\n");

	if (bsp(a, b, c, P1)) {
		println(WHT << "  The point P1 is " << GRN << "inside" << WHT << " the triangle.");
	}
	else {
		println(WHT << "  The point P1 is " << RED << "outside" << WHT << " the triangle.");
	}

	if (bsp(a, b, c, P2)) {
		println(WHT << "  Point P2 is " << GRN << "inside" << WHT << " the triangle.");
	}
	else {
		println(WHT << "  Point P2 is " << RED << "outside" << WHT << " the triangle.");
	}

	if (bsp(a, b, c, P3)) {
		println(WHT << "  And point P3 is " << GRN << "inside" << WHT << " the triangle.");
	}
	else {
		println(WHT << "  And point P3 is " << RED << "outside" << WHT << " the triangle.");
	}
	
	println("");
}
