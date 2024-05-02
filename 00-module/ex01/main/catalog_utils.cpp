/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:36:21 by julberna          #+#    #+#             */
/*   Updated: 2024/05/02 02:06:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	prompt(std::string &input, std::string msg) {

	std::cout << WHT << "┌ ";
	if (msg == "BASIC") {
		println("What would you like to do? Type: '" << GRN << "ADD"
			<< WHT << "', '" << YLW << "SEARCH" << WHT << "' or '"
			<< RED << "EXIT" << WHT << "'.");
	}
	else {
		println("Please, " << GRN << "select an index"
				<< WHT << " to display all its information or type '"
				<< YLW << "BACK" << WHT << "' or '" << RED << "EXIT" << WHT << "'.");
	}
	std::cout << WHT << "└─➤ " << DFL;
	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);
}

void	error(int flag) {
	println("");
	println("   💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢");
	println("   💢                                                    💢" << WHT);

	switch (flag) {
		case EMPTY_CNT:
			println("   💢 Oops, there are" << RED << " no contacts " << WHT << "to be shown yet... 🤡  💢");
			println("   💢      Try adding some using the command '" << GRN << "ADD" << WHT << "'.      💢");
			break ;

		case WRONG_CMD:
			println("   💢           🤨 Unrecognized command! 🤨              💢" << DFL);
			break ;

		case INDEX_OUT:
			println("   💢       🙄 Index out of bounds or wrong! 🙄          💢" << DFL);
			break ;
	}

	println("   💢                                                    💢");
	println("   💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢");
	println("");
}

void	goodbye(void) {
	println("\n     ✨  ✨   ✨  ✨  ✨  ✨  ✨  ✨  ✨  ✨  ✨   ✨  ✨  ");
	println("   ✨👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾✨");
	println("     👾                                                👾  " << YLW);
	println("   ✨👾              🥰 SEE YOU SOON! 🥰               👾✨" << DFL);
	println("     👾                                                👾  ");
	println("   ✨👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾✨");
	println("     ✨  ✨   ✨  ✨  ✨  ✨  ✨  ✨  ✨  ✨  ✨   ✨  ✨  \n");
	std::exit(EXIT_SUCCESS);
}
