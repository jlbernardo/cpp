/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 13:43:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "office.hpp"

void	testFormCreation(void) {

	println(WHT << "\n  To prevent idleness on our bureaucratic planet,"
				" we have created forms!\n")

	Form	form("Sign up", 149, 70);
	println("   Form	form(\"Sign up\", 149, 70);\n");
	println(form);

	next;
}

void	testFormGradeException(void) {

	println(WHT << "\n  Same as with bureaucrats, they can only be created"
				" with grades between " << GRN << "1" << WHT << " and "
				<< RED << "150" << WHT << ".\n\n")

	println("   Form	form(\"Sign up\", 0, 1);\n");
	std::cout << BLD << "     ";
	try {
		Form	form("Sign up", 0, 1);
		println(form);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	println("\n\n   Form	form(\"Sign up\", 1, 0);\n");
	std::cout << BLD << "     ";
	try {
		Form	form("Sign up", 1, 0);
		println(form);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	println("\n\n   Form	form(\"Sign up\", 1, 151);\n");
	std::cout << BLD << "     ";
	try {
		Form	form("Sign up", 1, 151);
		println(form);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	println("\n\n   Form	form(\"Sign up\", 151, 1);\n");
	std::cout << BLD << "     ";
	try {
		Form	form("Sign up", 151, 1);
		println(form);
	}
	catch (std::exception &e) {
		println(e.what());
	}

	next;
}

void	testFormSign(void) {

	println(WHT << "  Once a form is created...\n");

	Form	form("Sign up", 42, 5);
	println("   Form	form(\"Sign up\", 42, 5);\n");
	println(form);

	println(WHT << "\n\n And we have a few bureaucrats available,"
				" we can ask them to sign the forms.\n");
	println("   Bureaucrat	bureaucrat1(\"Julien Lestrange\", 70);");
	println("   Bureaucrat	bureaucrat2(\"Leta Lestrange\", 23);\n");
	Bureaucrat	bureaucrat1("Julien Lestrange", 70);
	Bureaucrat	bureaucrat2("Leta Lestrange", 23);
	println(bureaucrat1);
	println(bureaucrat2);

	next;

	println(WHT << "  If their grade is lower than the form's sign"
				" grade, they cannot sign it.\n");
	bureaucrat1.signForm(form);
	println("\n" << form);

	next;

	println(WHT << "  But if the grade is enough, the form's status is updated.\n");
	bureaucrat2.signForm(form);
	println("\n" << form);

	println("\n");
}
