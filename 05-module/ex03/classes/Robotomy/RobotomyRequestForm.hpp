/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 23:22:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class AForm;

# include "AForm.hpp"

/**
 * #### RobotomyRequestForm class
 * Inherits from AForm.
 * Robotomizes the target passed as parameter.
 */
class RobotomyRequestForm : public AForm {

public:
						/**
						 * @brief Constructs a new Robotomy Request Form object with an unknown target.
						 */
						RobotomyRequestForm(void);

						/**
						 * @brief Constructs a new Robotomy Request Form object with a target.
						 * @param target Target to robotomize.
						 */
						RobotomyRequestForm(const std::string &target);

						/**
						 * @brief Destroys the Robotomy Request Form.
						 */
						~RobotomyRequestForm(void);

						/**
						 * @brief Constructs a new Robotomy Request Form from a copy.
						 * @param copy Robotomy Request Form to copy from.
						 */
						RobotomyRequestForm(const RobotomyRequestForm &copy);

						/**
						 * @brief Assigns a Robotomy Request Form to another.
						 * @param rhs Robotomy Request Form to copy from.
						 * @return Reference to the current Robotomy Request Form.
						 */
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

						/**
						 * @brief Action performed when the Robotomy Request Form is executed.
						 */
	void				action(void) const;
};

#endif
