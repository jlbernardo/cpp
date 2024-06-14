/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:58:37 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 17:53:02 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <sstream>
# include <fstream>
# include <iostream>
# include <exception>
# include "general.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

/**
 * #### Form abstract class
 * It has a name, a signature status, a grade required to sign it
 * and a grade required to execute it.
 */
class AForm {

private:
	const std::string	_name;			// Form's name.
	const std::string	_target;		// Form's target.
	bool				_signed;		// Form's signature status.
	const int			_gradeToSign;	// Grade required to sign the form.
	const int			_gradeToExec;	// Grade required to execute the form.


public:
						/**
						 * @brief Constructs a new Irrelevant low grade form.
						 */
						AForm(void);

						/**
						 * @brief Destroys the Form.
						 */
	virtual				~AForm(void);

						/**
						 * @brief Constructs a new Form from a copy.
						 * @param copy Form to copy from.
						 */
						AForm(const AForm &copy);

						/**
						 * @brief Constructs a new Form.
						 * @param name Form's name.
						 * @param gradeToSign Grade required to sign the form.
						 * @param gradeToExec Grade required to execute the form.
						 */
						AForm(const std::string &name, int gradeToSign, int gradeToExec);

						/**
						 * @brief Constructs a new Form.
						 * @param name Form's name.
						 * @param gradeToSign Grade required to sign the form.
						 * @param gradeToExec Grade required to execute the form.
						 * @param target Form's target.
						 */
						AForm(const std::string &name, int gradeToSign, int gradeToExec, const std::string &target);

						/**
						 * @brief Assigns a Form to another.
						 * @param rhs Form to assign.
						 * @return Form& Assigned Form.
						 */
	AForm				&operator=(const AForm &rhs);

						/**
						 * @brief Gets the Form's name.
						 * @return const std::string& Form's name.
						 */
	const std::string	&getName(void) const;

						/**
						 * @brief Gets the Form's signature status.
						 * @return bool Form's signature status.
						 */
	bool				getSignedStatus(void) const;

						/**
						 * @brief Gets the Form's grade required to sign it.
						 * @return int Sign grade.
						 */
	int					getGradeToSign(void) const;

						/**
						 * @brief Gets the Form's grade required to execute it.
						 * @return int Execution grade.
						 */
	int					getGradeToExec(void) const;

						/**
						 * @brief Gets the Form's target.
						 * @return const std::string& Form's target.
						 */
	const std::string	&getTarget(void) const;

						/**
						 * @brief Signs the form.
						 * @param bureaucrat Bureaucrat to sign the form.
						 */
	virtual void		beSigned(const Bureaucrat &bureaucrat);

	virtual void		execute(const Bureaucrat &executor);

	virtual void		action(void) const = 0;

	/**
	 * #### GradeTooHighException class
	 * Exception thrown when the grade is too high.
	 */
	class GradeTooHighException : public std::exception {
		public:
			/**
			 * @brief Explains what was the exception.
			 * @return const char* The exception message.
			 */
			virtual const char	*what(void) const throw();
	};

	/**
	 * #### GradeTooLowException class
	 * Exception thrown when the grade is too low.
	 */
	class GradeTooLowException : public std::exception {
		public:
			/**
			 * @brief Explains what was the exception.
			 * @return const char* The exception message.
			 */
			virtual const char	*what(void) const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};
};

				/**
				 * @brief Outputs the Form to the output stream.
				 * @param out Output stream.
				 * @param form Form to output.
				 * @return std::ostream& The output stream.
				 */
std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
