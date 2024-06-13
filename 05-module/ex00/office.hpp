/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:28 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 13:54:45 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef OFFICE_HPP
# define OFFICE_HPP

# include "Bureaucrat.hpp"

		/**
		 * @brief Tests the creation of a Bureaucrat.
		 */
void	testBureaucratCreation(void);

		/**
		 * @brief Tests the creation of a Bureaucrat with a grade too high.
		 */
void	testGradeTooHighException(void);

		/**
		 * @brief Tests the creation of a Bureaucrat with a grade too low.
		 */
void	testGradeTooLowException(void);

		/**
		 * @brief Tests the incrementation of a Bureaucrat's grade.
		 */
void	testIncrementGrade(void);

		/**
		 * @brief Tests the decrementation of a Bureaucrat's grade.
		 */
void	testDecrementGrade(void);

#endif
