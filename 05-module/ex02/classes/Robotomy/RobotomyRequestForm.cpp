/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:42:30 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 22:42:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", 72, 45, "Unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45, target) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy) {
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return (*this);
}

void	RobotomyRequestForm::action(void) const {
	srand(time(NULL));

	int	success = rand() % 2;
	if (success) {
		println(RED << "     🧠 *Bzzzzzz rrrrrr rizzz* " << this->getTarget()
					<< " has been robotomized. 🧠");
	}
	else {
		println(PRP << "     😈 *Bzzzzzz rrrrrr rizzz* " << this->getTarget()
					<< " robotomization failed. 😈");
	}
}
