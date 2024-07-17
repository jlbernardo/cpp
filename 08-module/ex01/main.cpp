/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:42:27 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 13:08:14 by julberna         ###   ########.fr       */
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

	Span	listMany(10);
	int		values[] = {1, 87, 66, 3, 12, 42, 98, 2537, 5, 11};

	listMany.addMany(values);
	std::cout << WHT << "   ~ ADD MANY FROM INT LIST ~\n" << std::flush;
	listMany.print();
	println(RED << "  Shortest span: " << WHT << listMany.shortestSpan()
				<< " (" << listMany.lowerShortest() << ", " << listMany.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << listMany.longestSpan()
				<< " (" << listMany.lowerLongest() << ", " << listMany.upperLongest() << ")");

	next;

	Span	randomMany(10);

	randomMany.addMany(10);
	std::cout << WHT << "   ~ ADD MANY RANDOM FILL ~\n" << std::flush;
	randomMany.print();
	println(RED << "  Shortest span: " << WHT << randomMany.shortestSpan()
				<< " (" << randomMany.lowerShortest() << ", " << randomMany.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << randomMany.longestSpan()
				<< " (" << randomMany.lowerLongest() << ", " << randomMany.upperLongest() << ")");

	next;

	std::cout << WHT << "   ~ ADD BEYOND LIMIT SPAN ~\n" << std::flush;

	randomMany.print();
	println(" //Trying to add an 11th number to a size 10 span");
	std::cout << WHT << " span.addNumber(42): "<< std::flush;
	try {
		randomMany.addNumber(42);
		randomMany.print();
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
	println(RED << "  Shortest span: " << WHT << ginormous.shortestSpan()
				<< " (" << ginormous.lowerShortest() << ", " << ginormous.upperShortest() << ")");
	println(GRN << "   Longest span: " << WHT << ginormous.longestSpan()
				<< " (" << ginormous.lowerLongest() << ", " << ginormous.upperLongest() << ")");
}
