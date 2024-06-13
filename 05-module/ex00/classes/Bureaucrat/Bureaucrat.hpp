/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:10:51 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 12:24:45 by julberna         ###   ########.fr       */
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

class Bureaucrat {

private:
	int					_grade;			// Bureaucrat's grade, ranged from 1 to 150.
	const std::string	_name;			// Bureaucrat's name.

public:
						Bureaucrat(void);
						~Bureaucrat(void);
						Bureaucrat(const Bureaucrat &copy);
						Bureaucrat(const std::string &name, int grade);
	Bureaucrat			&operator=(const Bureaucrat &rhs);
	Bureaucrat			operator++(int);
	Bureaucrat			operator--(int);
	Bureaucrat			&operator++(void);
	Bureaucrat			&operator--(void);

	const std::string	&getName(void) const;
	int					getGrade(void) const;

	void				incrementGrade(void);
	void				decrementGrade(void);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream			&operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
