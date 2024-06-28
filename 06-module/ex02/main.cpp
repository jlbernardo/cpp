/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:23:53 by julberna          #+#    #+#             */
/*   Updated: 2024/06/28 13:20:39 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

int main (void) {
	Base *p = generate();

	println(WHT << "    Identify with reference:");
	std::cout << "    ";
	identify(*p);

	println(WHT << "\n    Identify with pointer:");
	std::cout << "    ";
	identify(p);

	delete p;

	println(WHT << "\n    Identify a NULL object:");
	std::cout << "    ";
	identify(NULL);
	println("");

	return (EXIT_SUCCESS);
}
