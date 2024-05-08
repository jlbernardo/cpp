/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:25 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 21:32:16 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {

	Harl		robot;
	std::string	input;

	bubble("robot/prompt.harl");
	while (true) {
		prompt(input);
		if (input == "EXIT")
			break ;
		if (input == "BACK") {
			bubble("robot/prompt.harl");
			continue ;
		}
		robot.complain(input);
	}
	bubble("robot/goodbye.harl");
}
