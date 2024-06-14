/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 13:38:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "office.hpp"

void	testBureaucratCreation(void) {

	println(WHT << "\n  In our new office, we can have all sorts of bureaucrats."
			" Let's create one!\n\n");

	Bureaucrat	bureaucrat("Julien Lestrange", 42);

	println("   Bureaucrat	bureaucrat(\"Julien Lestrange\", 42);\n");
	println(bureaucrat);

	println(WHT << "\n\n  The grades range from " << GRN << "1" << WHT << " to "
				<< RED << "150" << WHT << ", with 1 being the " << GRN << "highest"
				<< WHT << " and 150 the " << RED << "lowest" << WHT << ".");

	next;
}

void	testGradeTooHighException(void) {

	println(WHT << "  We can't have bureaucrats with a grade higher than 1."
			"\n  If we try to create one, we'll get "
			<< RED << "an exception" << WHT << ".\n\n");


	println("   Bureaucrat	bureaucrat(\"Julien Lestrange\", 0);\n");
	std::cout << BLD << "     ";

	try {
		Bureaucrat	bureaucrat("Julien Lestrange", 0);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	next;
}

void	testGradeTooLowException(void) {

	println(WHT << "  We also can't have bureaucrats with a grade lower than 150."
			"\n  They will also result in " << RED << "an exception" << WHT << ".\n\n");

	println("   Bureaucrat	bureaucrat(\"Julien Lestrange\", 151);\n");
	std::cout << BLD << "     ";

	try {
		Bureaucrat	bureaucrat("Julien Lestrange", 151);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	next;
}

void	testIncrementGrade(void) {

	println(WHT << "  Once a bureaucrat is created...\n\n");

	Bureaucrat	bureaucrat("Julien Lestrange", 2);
	println("   Bureaucrat	bureaucrat(\"Julien Lestrange\", 2);\n");
	println(bureaucrat);

	println(WHT << "\n\n  We can increment their grade.\n\n");
	println("   bureaucrat++;\n");
	std::cout << BLD;
	bureaucrat++;
	println(bureaucrat);

	println(WHT << "\n\n  But we still can't go over 1.\n\n");
	println("   bureaucrat++;\n");
	std::cout << BLD;
	bureaucrat++;

	next;
}

void	testDecrementGrade(void) {

	println(WHT << "  The same way, we can decrement a bureaucrat's grade.\n\n");

	Bureaucrat	bureaucrat("Julien Lestrange", 149);
	println("   Bureaucrat	bureaucrat(\"Julien Lestrange\", 149);\n");
	println(bureaucrat);

	println("\n   bureaucrat--;\n");
	std::cout << BLD;
	bureaucrat--;
	println(bureaucrat);

	println(WHT << "\n\n  But we can't go below 150.\n");
	println("   bureaucrat--;\n");
	std::cout << BLD;
	bureaucrat--;

	println("\n");
}
