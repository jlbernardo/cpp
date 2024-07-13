/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:19:13 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 23:32:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {

	try {
		if (argc != 2)
			throw std::invalid_argument("Wrong number of arguments!");

		BitcoinExchange	btc(argv[1]);
		
		btc.loadCSV();
		btc.analyzeInput();
	}
	catch (std::exception &e) {
		errorln("Error: " << e.what());
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
