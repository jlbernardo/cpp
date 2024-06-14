/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 18:24:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class AForm;

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
						RobotomyRequestForm(void);
						RobotomyRequestForm(const std::string &target);
						~RobotomyRequestForm(void);
						RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

	void				action(void) const;
};

#endif
