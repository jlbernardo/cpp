/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.canonical.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:18:27 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 21:28:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(char **argv) : _size(0) {

	validateInput(++argv);
	validateUniqueness();
	populateContainers();
	print();
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
