/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:10:51 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 16:39:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <exception>
# include "general.hpp"
# include "Form.hpp"

class Form;

/**
 * #### Bureaucrat class
 * It has a name and a grade, which ranges from 1 to 150.
 */
class Bureaucrat {

private:
	int					_grade;			// Bureaucrat's grade, ranged from 1 to 150.
	const std::string	_name;			// Bureaucrat's name.

public:
						/**
						 * @brief Constructs a new Unknown low grade Bureaucrat.
						 */
						Bureaucrat(void);

						/**
						 * @brief Destroys the Bureaucrat.
						 */
						~Bureaucrat(void);

						/**
						 * @brief Constructs a new Bureaucrat from a copy.
						 * @param copy Bureaucrat to copy from.
						 */
						Bureaucrat(const Bureaucrat &copy);

						/**
						 * @brief Constructs a new Bureaucrat.
						 * @param name Bureaucrat's name.
						 * @param grade Bureaucrat's grade.
						 */
						Bureaucrat(const std::string &name, int grade);

						/**
						 * @brief Assigns a Bureaucrat to another.
						 * @param rhs Bureaucrat to copy from.
						 * @return Updated Bureaucrat.
						 */
	Bureaucrat			&operator=(const Bureaucrat &rhs);

						/**
						 * @brief Post increments the Bureaucrat's grade.
						 * @return Updated Bureaucrat.
						 */
	Bureaucrat			operator++(int);

						/**
						 * @brief Post decrements the Bureaucrat's grade.
						 * @return Updated Bureaucrat.
						 */
	Bureaucrat			operator--(int);

						/**
						 * @brief Pre increments the Bureaucrat's grade.
						 * @return Reference to the updated Bureaucrat.
						 */
	Bureaucrat			&operator++(void);

						/**
						 * @brief Pre decrements the Bureaucrat's grade.
						 * @return Reference to the updated Bureaucrat.
						 */
	Bureaucrat			&operator--(void);


						/**
						 * @brief Gets the Bureaucrat's name.
						 * @return Bureaucrat's name.
						 */
	const std::string	&getName(void) const;

						/**
						 * @brief Gets the Bureaucrat's grade.
						 * @return Bureaucrat's grade.
						 */
	int					getGrade(void) const;


						/**
						 * @brief Attempts to increment the Bureaucrat's grade.
						 * @throw GradeTooHighException if the grade is already 1.
						 */
	void				incrementGrade(void);

						/**
						 * @brief Attempts to decrement the Bureaucrat's grade.
						 * @throw GradeTooLowException if the grade is already 150.
						 */
	void				decrementGrade(void);

						/**
						 * @brief Signs a form.
						 * @param form Form to sign.
						 */
	void				signForm(Form &form);

	/**
	 * #### GradeTooHighException class
	 * Exception thrown when trying to set a grade higher than 1.
	 */
	class GradeTooHighException : public std::exception {
		public:
			/**
			 * @brief Explains what was the exception.
			 * @return The exception message.
			 */
			virtual const char	*what(void) const throw();
	};

	/**
	 * #### GradeTooLowException class
	 * Exception thrown when trying to set a grade lower than 150.
	 */
	class GradeTooLowException : public std::exception {
		public:
			/**
			 * @brief Explains what was the exception.
			 * @return The exception message.
			 */
			virtual const char	*what(void) const throw();
	};
};

						/**
						 * @brief Outputs the Bureaucrat's name and grade.
						 * @param out Output stream.
						 * @param rhs Bureaucrat to output.
						 * @return The output stream.
						 */
std::ostream			&operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
