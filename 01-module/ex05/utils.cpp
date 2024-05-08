/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:38:45 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 21:17:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	prompt(std::string &input) {

	std::cout << WHT << "╭─────────────────────────────────────── •";
	std::cout << WHT << "\n╰─➤ " << DFL;
	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);
}

void	bubble(std::string file) {

	std::ifstream	speech(file.c_str());
	std::string		line;

	std::cout << "\033c";
	while (speech.good()) {
		getline(speech, line);
		println(WHT << line << DFL);
	}
	speech.close();
}
