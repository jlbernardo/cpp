/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/13 23:02:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "office.hpp"

void	introduction(void) {

	println(WHT << "\n  Now we have three different forms to test:\n");
	println(YLW << "       ✨ Presidential Pardons ✨"
				<< RED << "\n        🧠 Robotomy Requests 🧠"
				<< GRN << "\n       🌱 Shrubbery Creations 🌱");
	println(WHT << "\n  They all inherit from " << CYN << "AForm"
				<< WHT << ", which is now an "
				<< UND << "abstract class" << DFL << WHT << ".");

	println(WHT << "  Let's see how they work!");

	next;
}

void	testPardon(void) {

	println(WHT << "  First, we have the Presidential Pardon Form.");
	println(WHT << "  This form is used when someone needs a pardon from the President.\n\n");
	Bureaucrat	argus("Argus Filch", 6);
	Bureaucrat	sybill("Sybill Trelawney", 5);

	println(BLD << "   PresidentialPardonForm pardon(\"Narcissa\");\n");
	PresidentialPardonForm	pardon("Narcissa");
	println(pardon);

	next;

	println(WHT << "  If we try to execute it without signing it first, we get an error.\n");
	try {
		argus.executeForm(pardon);
	}
	catch (std::exception &e) {
		println(RED << "     💢 Execution failed:");
		println(BLD << "     " << e.what());
	}
	println("\n\n" << pardon);

	next;

	println(WHT << "  To sign this one, we only need a bureaucrat with\n  grade"
				<< GRN << " 25 or higher" << WHT << ", so any one of these two below can do it.\n");
	println(argus);
	println(sybill);

	println("");
	argus.signForm(pardon);

	println(WHT << "\n\n  And its status is, then, updated:");
	println("\n" << pardon);

	next;

	println(WHT << "  However, to execute it, we need a bureaucrat with a\n  grade"
				<< GRN << " 5 or higher" << WHT << ". So Argus cannot perform it.\n");
	argus.executeForm(pardon);

	println(WHT << "\n\n  But Sybill can!\n");
	sybill.executeForm(pardon);
	println("");

	next;
}

void	testRobotomy(void) {

	println(WHT << "  Up next, we have the Robotomy Request Form.");
	println(WHT << "  This form is used when people have been way too terrible.\n\n");
	Bureaucrat	remus("Remus Lupin", 72);
	Bureaucrat	tonks("Nymphadora Tonks", 45);

	println(BLD << "   RobotomyRequestForm robotomy(\"Bellatrix\");\n");
	RobotomyRequestForm	robotomy("Bellatrix");
	println(robotomy);

	println(WHT << "\n\n  The funny thing about this one, though, is that it only \n"
					"  has a 50% chance of success when executed. 😬");

	next;

	println(WHT << "  If we try to execute it without signing it first, it fails.\n");
	try {
		tonks.executeForm(robotomy);
	}
	catch (std::exception &e) {
		println(RED << "     💢 Execution failed:");
		println(BLD << "     " << e.what());
	}
	println("\n\n" << robotomy);

	next;

	println(WHT << "  And it needs a grade" << YLW << " 72 or higher"
				<< WHT << " to be signed.\n");
	println(remus);
	println(tonks);

	println("\n");
	remus.signForm(robotomy);
	println("\n\n" << robotomy);

	next;

	println(WHT << "  And again, grades need to be considered when trying to execute it.\n");
	remus.executeForm(robotomy);

	println(WHT << "\n\n  For this one, only Tonks is capable to perform the execution.\n");
	tonks.executeForm(robotomy);

	next;
}

void	testShrubbery(void) {

	println(WHT << "  At last, we have the Shrubbery Creation Form.");
	println(WHT << "  This one is used when someone has a garden that needs a touch up.\n\n");
	Bureaucrat	ron("Ron Weasley", 145);
	Bureaucrat	hermione("Hermione Granger", 66);

	println(BLD << "   ShrubberyCreationForm shrubbery(\"Hogwarts\");\n");
	ShrubberyCreationForm	shrubbery("Hogwarts");
	println(shrubbery);

	println(WHT << "\n\n  After it is executed, a new file is created, named "
				<< GRN << "target's name + \"_shrubbery\"" << WHT << ",\n  containing"
				" a photograph of the brand new tree planted at the location.");

	next;

	println(WHT << "  Again, we can't execute it without a signature.\n");
	try {
		hermione.executeForm(shrubbery);
	}
	catch (std::exception &e) {
		println(RED << "     💢 Execution failed:");
		println(BLD << "     " << e.what());
	}
	println("\n\n" << shrubbery);

	next;

	println(WHT << "  As trees are not sensitive matter, it can be signed by"
				"\n  almost anyone, since it only requires a grade"
				<< RED << " 145 or higher" << WHT << ".\n");
	println(ron);
	println(hermione);

	println("\n");
	ron.signForm(shrubbery);
	println("\n\n" << shrubbery);

	next;

	println(WHT << "  If Ron tried to execute this one, he would also get an error.\n");
	ron.executeForm(shrubbery);

	println(WHT << "\n\n  But Hermione can do it just fine.\n");
	hermione.executeForm(shrubbery);

	println(WHT << "\n\n  Wanna see what your new tree looks like? 🤭");
	next;
}
