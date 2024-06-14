/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:52:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 15:00:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

# define	MAX_FORMS 3

class Intern {

private:
	AForm			*robotomyRequest(std::string target);
	AForm			*shrubberyCreation(std::string target);
	AForm			*presidentialPardon(std::string target);

protected:
					Intern(void);
					Intern(Intern const &copy);
	Intern &		operator=(Intern const &copy);

public:
					~Intern(void);
	static Intern	&getInstance(void);

	AForm			*makeForm(const std::string &name, const std::string &target);

	class FormNotFoundException : public std::exception {
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream		&operator<<(std::ostream &out, Intern const &rhs);

#endif
