/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:52:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 16:14:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

# define	MAX_FORMS 3		// Maximum number of forms.

/**
 * #### Intern class
 * It is a singleton class, so only one instance can be created.
 * It can create forms based on the name and target given.
 * Accepted forms are: Robotomy Request, Shrubbery Creation and Presidential Pardon.
 */
class Intern {

private:
					/**
					 * @brief Creates a new Robotomy Request form.
					 * @param target Target of the form.
					 * @return AForm* New Robotomy Request form.
					 */
	AForm			*robotomyRequest(std::string target);

					/**
					 * @brief Creates a new Shrubbery Creation form.
					 * @param target Target of the form.
					 * @return AForm* New Shrubbery Creation form.
					 */
	AForm			*shrubberyCreation(std::string target);

					/**
					 * @brief Creates a new Presidential Pardon form.
					 * @param target Target of the form.
					 * @return AForm* New Presidential Pardon form.
					 */
	AForm			*presidentialPardon(std::string target);

protected:
					/**
					 * @brief Constructs a new Intern.
					 */
					Intern(void);

					/**
					 * @brief Constructs a new Intern from a copy.
					 * @param copy Intern to copy from.
					 */
					Intern(Intern const &copy);

					/**
					 * @brief Assigns an Intern to another.
					 * @param rhs Intern to copy from.
					 * @return Intern& New Intern.
					 */
	Intern &		operator=(Intern const &copy);

public:
					/**
					 * @brief Destroys the Intern.
					 */
					~Intern(void);

					/**
					 * @brief Gets the Intern instance.
					 * @return Intern& A reference to the instance.
					 */
	static Intern	&getInstance(void);

					/**
					 * @brief Creates a new form based on the name and target given.
					 * @param name Name of the form.
					 * @param target Target of the form.
					 * @return AForm* New form.
					 */
	AForm			*makeForm(const std::string &name, const std::string &target);

	/**
	 * #### FormNotFoundException class
	 * Exception thrown when the form name given is not found.
	 */
	class FormNotFoundException : public std::exception {
		public:
			/**
			 * @brief Explains what was the exception.
			 * @return const char* The exception message.
			 */
			virtual const char *what(void) const throw();
	};
};

					/**
					 * @brief Outputs the Intern message.
					 * @param out Output stream.
					 * @param rhs Intern to output.
					 * @return std::ostream& The output stream.
					 */
std::ostream		&operator<<(std::ostream &out, Intern const &rhs);

#endif
