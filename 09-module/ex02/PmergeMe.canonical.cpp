/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.canonical.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:18:27 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 04:10:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(char **argv) : _size(0) {

	validateInput(++argv);
	validateUniqueness();
	populateContainers();
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
		this->_size = rhs._size;
	}
	return (*this);
}

void	PmergeMe::calculate(void) {
	vectorSort();
	dequeSort();
}

void	PmergeMe::print(void) {
	std::cout << PRP << std::endl << "    Original: " << std::flush;
	for (vIter it  = this->_input.begin(); it != this->_input.end(); it++)
		std::cout << *it << " ";

	std::cout << BLU << std::endl << "      Sorted: " << std::flush;
	for (vIter it  = this->_vector.main.begin(); it != this->_vector.main.end(); it++)
		std::cout << *it << " ";

	println("");

	println(std::fixed << std::setprecision(4));

	println(WHT << " Time to process a range of " << this->_size << " elements with std::vector: " <<
			(this->_vector.time > this->_deque.time ? "\033[31;1m" : "\033[32;1m") << this->_vector.time << "μs");
	println(WHT << " Time to process a range of " << this->_size << " elements with std::deque : " <<
			(this->_vector.time > this->_deque.time ? "\033[32;1m" : "\033[31;1m") << this->_deque.time << "μs");
}
