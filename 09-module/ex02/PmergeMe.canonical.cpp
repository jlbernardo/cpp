/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.canonical.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:18:27 by julberna          #+#    #+#             */
/*   Updated: 2024/07/16 20:39:02 by julberna         ###   ########.fr       */
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
	if (notSorted()) {
		vectorSort();
		dequeSort();
	}
}

void	PmergeMe::print(void) {
	std::cout << PRP << std::endl << "    Original: " << std::flush;
	for (vIter it  = this->_input.begin(); it != this->_input.end(); it++)
		std::cout << *it << " ";

	std::cout << BLU << std::endl << "      Sorted: " << std::flush;
	for (vIter it  = this->_vector.main.begin(); it != this->_vector.main.end(); it++)
		std::cout << *it << " ";

	println("");

	println(std::fixed);
	println(WHT << " Time to process this range of " << this->_size << " elements with std::vector: " <<
			(this->_vector.time <= this->_deque.time ? GRN : RED) << this->_vector.time << "μs");
	println(WHT << " Time to process this range of " << this->_size << " elements with std::deque : " <<
			(this->_deque.time <= this->_vector.time ? GRN : RED) << this->_deque.time << "μs");
}
