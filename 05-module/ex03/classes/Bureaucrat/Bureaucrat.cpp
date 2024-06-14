/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:17:30 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 20:46:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150), _name("Unknown") {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _grade(grade), _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _grade(copy._grade), _name(copy._name) {
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

Bureaucrat	Bureaucrat::operator++(int) {
	Bureaucrat	tmp(*this);
	try {
		this->incrementGrade();
	}
	catch (GradeTooHighException &e) {
		println(RED << "     💢 Cannot increment:");
		println(BLD << "     " << e.what());
	}
	return (tmp);
}

Bureaucrat	Bureaucrat::operator--(int) {
	Bureaucrat	tmp(*this);
	try {
		this->decrementGrade();
	}
	catch (GradeTooLowException &e) {
		println(RED << "     💢 Cannot decrement:");
		println(BLD << "     " << e.what());
	}
	return (tmp);
}

Bureaucrat	&Bureaucrat::operator++(void) {
	try {
		this->incrementGrade();
	}
	catch (GradeTooHighException &e) {
		println(RED << "     💢 Cannot increment:");
		println(BLD << "     " << e.what());
	}
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--(void) {
	try {
		this->decrementGrade();
	}
	catch (GradeTooLowException &e) {
		println(RED << "     💢 Cannot decrement:");
		println(BLD << "     " << e.what());
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs) {
	std::string	color;

	if (rhs.getGrade() <= 50)
		color = GRN;
	else if (rhs.getGrade() <= 100)
		color = YLW;
	else
		color = RED;
	out << BLD << "     🧐 " << rhs.getName() << ": bureaucrat of grade "
		<< color << rhs.getGrade() << DFL << BLD << ". 🖋️";
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("💢 Bureaucrat grade too high. Maximum grade is 1. 💢");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("💢 Bureaucrat grade too low. Minimum grade is 150. 💢");
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		println(BLD << "     📝 " << this->getName() << GRN << " successfully"
			<< DFL << BLD << " signed the '" << form.getName() << "' form.");
	}
	catch (AForm::GradeTooLowException &e) {
		println(BLD << "     " << e.what());
		println(BLD << "     💢 " << this->getName() << RED << " cannot "
			<< DFL << BLD << "sign the '" << form.getName() << "' form");
	}
}

void	Bureaucrat::executeForm(AForm &form) {
	try {
		form.execute(*this);
		println(BLD << "     📝 " << this->getName() << GRN << " successfully"
			<< DFL << BLD << " executed the '" << form.getName() << "' form.");
	}
	catch (AForm::GradeTooLowException &e) {
		println(BLD << "     " << e.what());
		println(BLD << "     💢 " << this->getName() << RED << " cannot "
			<< DFL << BLD << "execute the '" << form.getName() << "' form.");
	}
}
