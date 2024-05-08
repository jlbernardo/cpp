/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:25 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 22:41:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {

	int			option;
	Harl		robot;

	option = verification(argc, argv);
	switch (option) {
		case DEBUG:
			robot.complain("DEBUG");

		case INFO:
			robot.complain("INFO");

		case WARNING:
			robot.complain("WARNING");

		case ERROR:
			robot.complain("ERROR");
	}
}
