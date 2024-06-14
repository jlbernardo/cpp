/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   office.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:35:13 by julberna          #+#    #+#             */
/*   Updated: 2024/06/14 16:05:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "office.hpp"

void	introduction(void) {

	println(WHT << "\n  Turns out, filling out forms can be quite annoying\n"
					"  and our spoiled bureaucrats started refusing to do it. 🙄\n");

	println(WHT << "  So, to stop the complaints, we decided to hire " << YLW <<
					"an intern" << WHT << "!\n"
					"  They needed some experience and said they'd do anything,\n"
					"  including filling up any form we ask them to. 📝\n\n");

	println(YLW << "                        #############");
	println(YLW << "                        ##         ##");
	println(YLW << "                        #  ~~   ~~  #");
	println(YLW << "                        #  ()   ()  #");
	println(YLW << "                        (     ^     )");
	println(YLW << "                         |         |");
	println(YLW << "                         |  {===}  |");
	println(YLW << "                          \\       /");
	println(YLW << "                         /  -----  \\");
	println(YLW << "                      ---  |%\\ /%|  ---");
	println(YLW << "                     /     |%%%%%|     \\");
	println(YLW << "                           |%/ \\%|");

	println(WHT << "\n\n  Can you help me checking that they are doing their job right?");

	next;

	println(WHT << "  To create anything, we need to inform the intern two things:\n");
	println(WHT << "   - the " << GRN << "name" << WHT << " of the form we want to create");
	println(WHT << "   - the " << RED << "target" << WHT << " of the form");

	println(WHT << "\n\n  Let's initialize our intern instance:\n\n");
	println(BLD << "   Intern &intern = Intern::getInstance();\n");

	Intern	&intern = Intern::getInstance();
	println(intern);

	println(WHT << "\n\n  Cool, they are ready to rock!");
	next;
}

void	testIntern(void) {

	Intern	&intern = Intern::getInstance();

	println(WHT << "  Before we start, it's good to know that we must type the information correctly.");
	println(WHT << "  If we don't, the intern will not be able to create the form we want.\n");

	println(WHT << "\n  For example:\n");

	println("   AForm	*form = intern.makeForm(\"debt settlement\", \"Cadet\");\n");
	try {
		AForm	*form = intern.makeForm("debt settlement", "Cadet");
		println(*form);
		delete form;
	}
	catch (std::exception &e) {
		println(RED << "     💢 Creation failed:");
		println(BLD << "     " << e.what());
	}
	println(WHT << "\n\n  This form doesn't exists, so they don't know what to write in it. 🤷");

	next;

	println(WHT << "  That being said, let's create one of each form.\n");

	println("   AForm	*pardon = intern.makeForm(\"presidential pardon\", \"Dobby\");");
	println("   AForm	*robotomy = intern.makeForm(\"robotomy request\", \"Peter Pettigrew\");");
	println("   AForm	*shrubbery = intern.makeForm(\"shrubbery creation\", \"the Burrow\");\n\n");

	AForm	*pardon = intern.makeForm("presidential pardon", "Dobby");
	AForm	*robotomy = intern.makeForm("robotomy request", "Peter Pettigrew");
	AForm	*shrubbery = intern.makeForm("shrubbery creation", "the Burrow");

	println("\n\n" << *pardon);
	println("\n\n" << *robotomy);
	println("\n\n" << *shrubbery);

	next;

	println(WHT << "  Now we can try to sign and execute these new forms.\n\n");

	Bureaucrat	albus("Albus Dumbledore", 1);
	println(albus << "\n\n");

	albus.signForm(*pardon);
	albus.signForm(*robotomy);
	albus.signForm(*shrubbery);

	println("\n");

	println(*pardon);
	println(*robotomy);
	println(*shrubbery);

	println("\n");

	pardon->execute(albus);
	robotomy->execute(albus);
	shrubbery->execute(albus);

	delete pardon;
	delete robotomy;
	delete shrubbery;

	next;

	println(WHT << "\n\n  Pretty cool, right? The intern really can do ✨ anything!✨\n");
	println(WHT << "  The last step is to check if the tree was\n  actually planted at"
					" the Weasley's house. 🧐");

	next;
}
