/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:01:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 05:01:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		println(RED << "\n Error: wrong number of arguments!");

	RPN	rpn(argv[1]);

	rpn.calculate();
	next;

	return (EXIT_SUCCESS);
}
