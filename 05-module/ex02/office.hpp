/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:28 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 23:17:05 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef OFFICE_HPP
# define OFFICE_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

		/**
		 * @brief Introductory message.
		 */
void	introduction(void);

		/**
		 * @brief Tests the PresidentialPardonForm class.
		 */
void	testPardon(void);

		/**
		 * @brief Tests the RobotomyRequestForm class.
		 */
void	testRobotomy(void);

		/**
		 * @brief Tests the ShrubberyCreationForm class.
		 */
void	testShrubbery(void);

#endif
