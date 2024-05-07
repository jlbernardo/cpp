/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:06:48 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:29:22 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char **argv) {

	std::ifstream	origin;
	if (!validation(argc, argv, origin))
		std::exit(EXIT_FAILURE);

	std::ofstream	result;
	replace(origin, result, argv);

	return (EXIT_SUCCESS);
}
