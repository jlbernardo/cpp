/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:47:12 by julberna          #+#    #+#             */
/*   Updated: 2024/07/07 17:39:13 by julberna         ###   ########.fr       */
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

	println("");

	try {
		println(WHT << "   1) " GRN << *easyfind(vector, needle[0]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	try {
		println(WHT << "   2) " GRN << *easyfind(deque, needle[1]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	try {
		println(WHT << "   3) " GRN << *easyfind(list, needle[2]));
	}
	catch (std::runtime_error &e) {
		println(RED << e.what());
	}

	println("");
}
