/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:38:45 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 22:48:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	verification(int argc, char **argv) {

	std::string	options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc == 2) {
		std::string cmd(argv[1]);

		for (std::string::iterator it = cmd.begin(); it != cmd.end(); it++)
			*it = (char)toupper(*it);

		for (int i = 0; i < MAX_OPTIONS; i++) {
			if (options[i] == cmd)
				return (i);
		}
	}
	bubble("robot/goodbye.harl");
	std::exit(EXIT_SUCCESS);
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
