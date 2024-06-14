/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:46:00 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 22:23:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation", 145, 137, "Unknown") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137, target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy) {
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return (*this);
}

void	ShrubberyCreationForm::action(void) const {

	std::string		filename = this->getTarget() + "_shrubbery";
	std::string		origin("./classes/Shrubbery/tree.txt");
	std::ofstream	file;
	std::ifstream	tree;

	file.open(filename.c_str(), std::fstream::out);
	tree.open(origin.c_str(), std::fstream::in);

	if (file && tree) {
		std::string line;
		getline(tree, line, '\0');
		file << line << std::endl;
		println(GRN << "     🌱 Shrubbery creation form has been executed. 🌱");
	}
	else {
		errorln("     Error:\n" << YLW << "  The seed didn't take, please try again!");
	}
	file.close();
	tree.close();
}
