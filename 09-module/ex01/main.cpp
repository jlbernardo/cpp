/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:01:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 14:08:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {

	clean;

	if (argc == 2) {
		RPN	rpn(argv[1]);

		rpn.calculate();
		next;

		return (EXIT_SUCCESS);
	}

	println(RED << "\n Error: wrong number of arguments!");
	next;

	return (EXIT_SUCCESS);
}
