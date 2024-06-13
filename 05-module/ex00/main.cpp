/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:28:56 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 21:35:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "office.hpp"

int	main(void) {
	testBureaucratCreation();
	testGradeTooHighException();
	testGradeTooLowException();
	testIncrementGrade();
	testDecrementGrade();
}
