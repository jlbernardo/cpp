/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:06:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:41 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("Irrelevant form"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

Form::~Form(void) {
}

Form::Form(const Form &copy)
	:	_name(copy._name),				 _signed(copy._signed),
		_gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec) {
}

Form	&Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
		const_cast<std::string &>(this->_name) = rhs._name;
		const_cast<int &>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int &>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return (*this);
}

const std::string	&Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSignedStatus(void) const {
	return (this->_signed);
}

int		Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int		Form::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("💢 Grade too high! 💢");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("💢 Grade too low! 💢");
}

std::ostream	&operator<<(std::ostream &out, const Form &rhs) {
	std::string	signColor;
	std::string	execColor;
	std::string	formColor;

	if (rhs.getGradeToSign() <= 50)
		signColor = GRN;
	else if (rhs.getGradeToSign() <= 100)
		signColor = YLW;
	else
		signColor = RED;

	if (rhs.getGradeToExec() <= 50)
		execColor = GRN;
	else if (rhs.getGradeToExec() <= 100)
		execColor = YLW;
	else
		execColor = RED;

	formColor = signColor;
	if (rhs.getGradeToSign() > rhs.getGradeToExec())
		formColor = execColor;

	std::string signStatusColor = rhs.getSignedStatus() ? GRN : RED;
	std::string formStatus = signStatusColor + (rhs.getSignedStatus() ? "signed" : "not signed");

	out << BLD
		<< "     📜 '" << formColor << rhs.getName() << DFL << BLD << "' form" << "\n"
		<< "     🖋️  Grade to sign: " << signColor << rhs.getGradeToSign() << "\n" << DFL << BLD
		<< "     ⚖️  Grade to exec: " << execColor << rhs.getGradeToExec() << "\n" << DFL << BLD
		<< "     📝  Sign status : " << formStatus;
	return (out);
}
