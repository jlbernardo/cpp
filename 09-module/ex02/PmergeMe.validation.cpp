/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.validation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:57 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 21:33:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::validateInput(char **argv) {

	if (!*argv)
		return ;

	std::string	token(*argv);
	for (std::string::iterator it = token.begin(); it != token.end(); it++) {
		if (*it == '-')
			throw std::invalid_argument("negative numbers are not supported!");
		if (!std::isdigit(*it) && *it != '+')
			throw std::invalid_argument("unexpected character found!");
	}

	this->_input.push_back(std::strtol(*argv, 0, 10));
	PmergeMe::validateInput(++argv);
}

void	PmergeMe::validateUniqueness(void) {

	std::vector<int>	check(this->_input);

	std::sort(check.begin(), check.end());
	for (std::vector<int>::iterator it = check.begin() + 1; it != check.end(); it++) {
		if (*it == *(it - 1))
			throw std::invalid_argument("duplicated element found on input!");
	}
}

void	PmergeMe::populateContainers(void) {

	for (std::vector<int>::iterator it = this->_input.begin(); it != this->_input.end(); it++) {
		this->_deque.c.push_back(*it);
		this->_vector.c.push_back(*it);
		this->_size++;
	}
}

void	PmergeMe::print(void) {

	std::cout << std::endl << BLU << "   Vector: " << std::flush;
	for (std::vector<int>::iterator it = this->_vector.c.begin(); it != this->_vector.c.end(); it++)
		std::cout << *it << " " << std::flush;

	std::cout << std::endl << PRP << "    Deque: " << std::flush;
	for (std::vector<int>::iterator it = this->_vector.c.begin(); it != this->_vector.c.end(); it++)
		std::cout << *it << " " << std::flush;

	println("");
}
