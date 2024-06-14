/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:56:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 15:16:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

Intern::Intern(Intern const &copy) {
	*this = copy;
}

Intern	&Intern::operator=(Intern const &copy) {
	(void)copy;
	return *this;
}

Intern	&Intern::getInstance(void) {
	static Intern	instance;
	return (instance);
}

const char	*Intern::FormNotFoundException::what(void) const throw() {
	return ("💢 Form not found! 💢");
}

AForm	*Intern::robotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::shrubberyCreation(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::presidentialPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) {

	std::string	forms[MAX_FORMS] =	{"robotomy request",
									"shrubbery creation",
									"presidential pardon"};

	AForm	*(Intern::*create[MAX_FORMS])(std::string) =
									{&Intern::robotomyRequest,
									&Intern::shrubberyCreation,
									&Intern::presidentialPardon};

	for (std::string::iterator it = const_cast<std::string &>(name).begin(); it != name.end(); it++)
		*it = (char)tolower(*it);

	for (int type = 0; type < MAX_FORMS; type++) {
		if (forms[type] == name) {
			println(BLD << "     🤓 The intern has created a " << forms[type] << " form. 📄");
			return (this->*create[type])(target);
		}
	}

	throw FormNotFoundException();
	return (NULL);
}

std::ostream	&operator<<(std::ostream &out, Intern const &rhs) {
	(void)rhs;
	out << BLD << "     🤓 What can I help you with today?";
	return (out);
}
