/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:42:27 by julberna          #+#    #+#             */
/*   Updated: 2024/07/11 00:05:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	Span	regular(10);

	for (int i = 0; i < 10; i++)
		regular.addNumber(i * i);
	std::cout << WHT << "\n   ~ REGULAR SPAN ~\n" << std::flush;
	regular.print();
	println(RED << "  Shortest span: " << WHT << regular.shortestSpan()
				<< " (" << regular.lowerShortest() << ", " << regular.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << regular.longestSpan()
				<< " (" << regular.lowerLongest() << ", " << regular.upperLongest() << ")");

	next;

	Span	many(10);

	many.addMany(10);
	std::cout << WHT << "   ~ ADD MANY SPAN ~\n" << std::flush;
	many.print();
	println(RED << "  Shortest span: " << WHT << many.shortestSpan()
				<< " (" << many.lowerShortest() << ", " << many.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << many.longestSpan()
				<< " (" << many.lowerLongest() << ", " << many.upperLongest() << ")");

	next;

	std::cout << WHT << "   ~ ADD BEYOND LIMIT SPAN ~\n" << std::flush;

	many.print();
	println(" //Trying to add an 11th number to a size 10 span");
	std::cout << WHT << " span.addNumber(42): "<< std::flush;
	try {
		many.addNumber(42);
		many.print();
	}
	catch (std::overflow_error &e) {
	println(PRP << e.what());
	}

	next;

	Span	empty(10);

	std::cout << WHT << "   ~ EMPTY SPAN ~\n" << std::flush;
	empty.print();
	std::cout << RED << "  Shortest span: ";
	try {
		println(empty.shortestSpan());
	}
	catch (std::range_error &e) {
		println(PRP << e.what());
	}
	std::cout << GRN << "   Longest span: ";
	try {
		println(empty.longestSpan());
	}
	catch (std::range_error &e) {
		println(PRP << e.what());
	}

	next;

	Span	single(10);

	std::cout << WHT << "   ~ SINGLE SPAN ~\n" << std::flush;
	single.addNumber(42);
	single.print();
	std::cout << RED << "  Shortest span: ";
	try {
		println(single.shortestSpan());
	}
	catch (std::range_error &e) {
		println(PRP << e.what());
	}
	std::cout << GRN << "   Longest span: ";
	try {
		println(single.longestSpan());
	}
	catch (std::range_error &e) {
		println(PRP << e.what());
	}

	next;

	Span	ginormous(10000);

	std::cout << WHT << "   ~ GINORMOUS SPAN ~\n" << std::flush;
	ginormous.addMany(10000);
	ginormous.print();
	println(RED << "  Shortest span: " << WHT << many.shortestSpan()
				<< " (" << many.lowerShortest() << ", " << many.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << many.longestSpan()
				<< " (" << many.lowerLongest() << ", " << many.upperLongest() << ")");
}
