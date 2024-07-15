/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.validation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:57 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 06:54:47 by julberna         ###   ########.fr       */
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
	for (vIter it = check.begin() + 1; it != check.end(); it++) {
		if (*it == *(it - 1))
			throw std::invalid_argument("duplicated element found on input!");
	}
}

void	PmergeMe::populateContainers(void) {

	this->_deque.time = 0;
	this->_vector.time = 0;

	for (vIter it = this->_input.begin(); it != this->_input.end(); it++) {
		this->_deque.c.push_back(*it);
		this->_vector.c.push_back(*it);
		this->_size++;
	}
}
