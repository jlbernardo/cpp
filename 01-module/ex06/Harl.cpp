/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:32 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 22:55:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::string	input("not empty");

	bubble("robot/debug.harl");
	while (!input.empty())
		getline(std::cin, input);
}

void	Harl::info(void) {
	std::string	input("not empty");

	bubble("robot/info.harl");
	while (!input.empty())
		getline(std::cin, input);
}

void	Harl::warning(void) {
	std::string	input("not empty");

	bubble("robot/warning.harl");
	while (!input.empty())
		getline(std::cin, input);
}

void	Harl::error(void) {
	bubble("robot/error.harl");
}

void	Harl::complain(std::string level) {

	int			option = 0;
	void		(Harl::*comments[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (option < MAX_OPTIONS) {
		if (names[option] == level) {
			(this->*comments[option])();
			return ;
		}
		option++;
	}
	bubble("robot/wrong.harl");
}
