/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:28 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 20:59:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef OFFICE_HPP
# define OFFICE_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;

void	introduction(void);
void	testPardon(void);
void	testRobotomy(void);
void	testShrubbery(void);

#endif
