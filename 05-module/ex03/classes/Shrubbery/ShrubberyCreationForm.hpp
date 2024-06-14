/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:45:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 23:23:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

/**
 * #### ShrubberyCreationForm class
 * Inherits from AForm.
 * Creates a shrubbery file with a picture of the tree planted at the target location.
 */
class ShrubberyCreationForm : public AForm {

public:
							/**
							 * @brief Constructs a new Shrubbery Creation Form object with an unknown target.
							 */
							ShrubberyCreationForm(void);

							/**
							 * @brief Constructs a new Shrubbery Creation Form object with a target.
							 * @param target Target to plant a tree.
							 */
							ShrubberyCreationForm(const std::string &target);

							/**
							 * @brief Destroys the Shrubbery Creation Form.
							 */
							~ShrubberyCreationForm(void);

							/**
							 * @brief Constructs a new Shrubbery Creation Form from a copy.
							 * @param copy Shrubbery Creation Form to copy from.
							 */
							ShrubberyCreationForm(const ShrubberyCreationForm &copy);

							/**
							 * @brief Assigns a Shrubbery Creation Form to another.
							 * @param rhs Shrubbery Creation Form to copy from.
							 * @return Reference to the current Shrubbery Creation Form.
							 */
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

							/**
							 * @brief Action performed when the Shrubbery Creation Form is executed.
							 */
	void					action(void) const;
};

#endif
