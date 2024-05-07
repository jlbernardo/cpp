/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:44:57 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 17:29:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

bool	validation(int argc, char **argv, std::ifstream &origin) {

	if (argc != 4) {
		error("Error:\n" << YLW << "Wrong number of parameters.");
		return (false);
	}

	origin.open(argv[1], std::fstream::in);

	if (!origin.is_open()) {
		error("Error:\n" << YLW << "Failed to open file for reading.");
		return (false);
	}

	return (true);
}

void	replace(std::ifstream &origin, std::ofstream &result, char **argv) {

	std::string		line;
	std::string		s1((std::string)argv[2]);
	std::string		s2((std::string)argv[3]);
	std::string		name((std::string)argv[1] + ".replace");

	result.open(name.c_str(), std::fstream::out);
	while (origin.good()) {
		getline(origin, line);
		while (line.find(s1) != std::string::npos) {
			std::size_t pos = line.find(s1);
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		result << line << std::endl;
	}
	origin.close();
	result.close();
}
