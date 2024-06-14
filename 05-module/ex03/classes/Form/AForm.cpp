/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:06:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 22:01:12 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
	:	_name("Irrelevant form"), _target("Unknown"), _signed(false),
		_gradeToSign(150), _gradeToExec(150) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
	:	_name(name), _target("Unknown"), _signed(false),
		_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec, const std::string &target)
	:	_name(name), _target(target), _signed(false),
		_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

AForm::~AForm(void) {
}

AForm::AForm(const AForm &copy)
	:	_name(copy._name), _target(copy._target), _signed(copy._signed),
		_gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec) {
}

AForm	&AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
		const_cast<std::string &>(this->_target) = rhs._target;
		const_cast<std::string &>(this->_name) = rhs._name;
		const_cast<int &>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int &>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return (*this);
}

const std::string	&AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSignedStatus(void) const {
	return (this->_signed);
}

int		AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int		AForm::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

const std::string	&AForm::getTarget(void) const {
	return (this->_target);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat &bureaucrat) {
	if (!this->_signed) {
		throw FormNotSignedException();
	}
	if (bureaucrat.getGrade() > this->_gradeToExec) {
		throw GradeTooLowException();
	}
	this->action();
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("💢 Grade too high! 💢");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("💢 Grade too low! 💢");
}

const char	*AForm::FormNotSignedException::what(void) const throw() {
	return ("💢 Form not signed yet! 💢");
}

std::ostream	&operator<<(std::ostream &out, const AForm &rhs) {
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

	if (rhs.getName() == "Robotomy Request")
		formColor = RED;
	else if (rhs.getName() == "Presidential Pardon")
		formColor = YLW;
	else
		formColor = GRN;

	std::string signStatusColor = rhs.getSignedStatus() ? GRN : RED;
	std::string formStatus = signStatusColor + (rhs.getSignedStatus() ? "signed" : "not signed");

	out << BLD
		<< "     📜 '" << formColor << rhs.getName() << DFL << BLD << "' 📜" << "\n\n"
		<< "     ⚖️  Exec grade : " << execColor << rhs.getGradeToExec() << "\n" << DFL << BLD
		<< "     🖋️  Sign grade : " << signColor << rhs.getGradeToSign() << "\n" << DFL << BLD
		<< "     🎯 Form target: " << rhs.getTarget() << "\n" << DFL << BLD
		<< "     📝 Sign status: " << formStatus;
	return (out);
}
