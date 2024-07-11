/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:47:12 by julberna          #+#    #+#             */
/*   Updated: 2024/07/11 00:04:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int	main(void) {

	int					needle[] = {41, 42, 43};
	int					values[] = {5, 17, 98, 42, 33};
	std::list<int>		list(values, values + sizeof(values) / sizeof(int));
	std::deque<int>		deque(values, values + sizeof(values) / sizeof(int));
	std::vector<int>	vector(values, values + sizeof(values) / sizeof(int));

	println(WHT << "\n   We will create 3 containers with the same content: a "
				<< PRP << "list" << WHT << ", a " << YLW << "deque"
				<< WHT << " and a " << BLU << "vector" << WHT << ".");
	println("");
	println(PRP << "    list(" << WHT << "5, 17, 98, 42, 33" << PRP << ")");
	println(YLW << "   deque(" << WHT << "5, 17, 98, 42, 33" << YLW << ")");
	println(BLU << "  vector(" << WHT << "5, 17, 98, 42, 33" << BLU << ")");
	println("");

	println(WHT << "\n   With these, we can try to find the values " << needle[0]
				<< ", " << needle[1] << " and " << needle[2] << ":\n");

	try {
		println(WHT << "   find(" << BLU << "vector" << WHT << ", " << needle[0]
					<< "): " << GRN << *easyfind(vector, needle[0]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	try {
		println(WHT << "    find(" << YLW << "deque" << WHT << ", " << needle[1]
					<< "): " << GRN << *easyfind(deque, needle[1]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	try {
		println(WHT << "     find(" << PRP << "list" << WHT << ", " << needle[2]
					<< "): " << GRN << *easyfind(list, needle[2]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	println(WHT << "\n\n   Try changing the values on the main and see how the tests behave! ദ്ദി（• ˕ •マ.ᐟ");
}
