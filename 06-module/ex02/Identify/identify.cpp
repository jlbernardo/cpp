/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:30:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 19:10:39 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base	*generate(void) {
	srand(time(NULL));

	std::cout << "\n     " << GRN;
	switch (rand() % 3) {
		case 0:
			println("Type A object created.\n");
			return (new A);
		case 1:
			println("Type B object created.\n");
			return (new B);
		case 2:
			println("Type C object created.\n");
			return (new C);
		default:
			println(RED << "An error has occured while creating the object.\n");
			return (NULL);
	}
}

void	identify(Base *p) {
	if (p) {
		identify(*p);
		return ;
	}
	println(RED << "Cannot identify a NULL object.");
}

void	identify(Base &p) {
	std::string	type("Unknown");

	try {
		A a = dynamic_cast<A &>(p);
		type = "A";
	}
	catch (std::exception &e) {
		try {
			B b = dynamic_cast<B &>(p);
			type = "B";
		}
		catch (std::exception &e) {
			try {
				C c = dynamic_cast<C &>(p);
				type = "C";
			}
			catch (std::exception &e) {
				;
			}
		}
	}

	println("Type: " << type);
}
