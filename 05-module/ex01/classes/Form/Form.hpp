/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:58:37 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <exception>
# include "general.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	_name;			// Form's name.
	bool				_signed;		// Form's signature status.
	const int			_gradeToSign;	// Grade required to sign the form.
	const int			_gradeToExec;	// Grade required to execute the form.

public:
						Form(void);
						~Form(void);
						Form(const Form &copy);
						Form(const std::string &name, int gradeToSign, int gradeToExec);
	Form				&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	bool				getSignedStatus(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;

	void				beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
