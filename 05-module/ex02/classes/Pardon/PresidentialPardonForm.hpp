/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:01:01 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 18:25:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class AForm;

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
							PresidentialPardonForm(void);
							PresidentialPardonForm(const std::string &target);
							~PresidentialPardonForm(void);
							PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

	void					action(void) const;
};

#endif
