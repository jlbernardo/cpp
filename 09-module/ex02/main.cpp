/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:50:41 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 03:52:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {

	clean;

	try {
		if (argc < 2)
			throw std::logic_error("Insufficient arguments!");

		PmergeMe	mis(argv);

		mis.calculate();
		mis.print();
	}
	catch (std::exception &e) {
		println(RED << std::endl << " Error: " << e.what());
	}

	// next;
}
