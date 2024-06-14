/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:01:01 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 23:21:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class AForm;

# include "AForm.hpp"

/**
 * #### PresidentialPardonForm class
 * Inherits from AForm.
 * Grants a presidential pardon to the target passed as parameter.
 */
class PresidentialPardonForm : public AForm {

public:
							/**
							 * @brief Constructs a new Presidential Pardon Form object with an unknown target.
							 */
							PresidentialPardonForm(void);

							/**
							 * @brief Constructs a new Presidential Pardon Form object with a target.
							 * @param target Target to pardon.
							 */
							PresidentialPardonForm(const std::string &target);

							/**
							 * @brief Destroys the Presidential Pardon Form.
							 */
							~PresidentialPardonForm(void);

							/**
							 * @brief Constructs a new Presidential Pardon Form from a copy.
							 * @param copy Presidential Pardon Form to copy from.
							 */
							PresidentialPardonForm(const PresidentialPardonForm &copy);

							/**
							 * @brief Assigns a Presidential Pardon Form to another.
							 * @param rhs Presidential Pardon Form to copy from.
							 * @return Reference to the current Presidential Pardon Form.
							 */
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

							/**
							 * @brief Action performed when the Presidential Pardon Form is executed.
							 */
	void					action(void) const;
};

#endif
