/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:19:13 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 01:22:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		errorln("Error:\nWrong number of arguments!");
		return (EXIT_FAILURE);
	}

	(void)argv;
	BitcoinExchange::loadCSV();
	BitcoinExchange::printCSV();

	return (EXIT_SUCCESS);
}
