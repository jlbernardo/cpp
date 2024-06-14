/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:45:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 18:24:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {

public:
							ShrubberyCreationForm(void);
							ShrubberyCreationForm(const std::string &target);
							~ShrubberyCreationForm(void);
							ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

	void					action(void) const;
};

#endif
