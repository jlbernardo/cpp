/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:40:03 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 06:41:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::vectorSort(void) {

	std::vector<intPair>	pairs;

	_vector.time = clock();

	createOddElement();
	createSortedPairs(pairs);
	createMainAndPend(pairs);
	createJacobsthalNumbers();
	createInsertionOrder();
	insertInOrder();

	_vector.time = (clock() - _vector.time) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::createOddElement(void) {
	_vector.odd = -1;

	if (_vector.c.size() % 2 != 0) {
		_vector.odd = _vector.c.back();
		_vector.c.pop_back();
	}
}

void	PmergeMe::createSortedPairs(vPair &pairs) {

	for (vIter it = _vector.c.begin(); it < _vector.c.end(); it += 2) {

		intPair		pair(*it, *(it + 1));

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);

		pairs.push_back(pair);
	}

	std::sort(pairs.begin(), pairs.end());
}

void	PmergeMe::createMainAndPend(vPair &pairs) {

	for (vPairIter it = pairs.begin(); it != pairs.end(); it++)
		_vector.main.push_back(it->first);

	for (vPairIter it = pairs.begin(); it != pairs.end(); it++)
		_vector.pend.push_back(it->second);

	if (_vector.odd != -1)
		_vector.pend.push_back(_vector.odd);
}

void	PmergeMe::createJacobsthalNumbers(void) {

	_vector.jacobsthal.push_back(0);
	_vector.jacobsthal.push_back(1);

	int nextNumber = *(_vector.jacobsthal.end() - 2) * 2 + _vector.jacobsthal.back();

	while (nextNumber < static_cast<int>(_vector.pend.size() - 1)) {
		_vector.jacobsthal.push_back(nextNumber);
		nextNumber = *(_vector.jacobsthal.end() - 2) * 2 + _vector.jacobsthal.back();
	}

	_vector.jacobsthal.erase(_vector.jacobsthal.begin() + 1);
}

void	PmergeMe::createInsertionOrder(void) {

	_vector.insertionOrder.push_back(_vector.jacobsthal.front());

	while (_vector.insertionOrder.size() < _vector.pend.size()) {
		_vector.jacobsthal.erase(_vector.jacobsthal.begin());

		if (!_vector.jacobsthal.empty()) {
			int	last = _vector.insertionOrder.back();
			int	jacob  = _vector.jacobsthal.front();

			_vector.insertionOrder.push_back(jacob--);
			while (jacob > last && _vector.insertionOrder.size() < _vector.pend.size()) {
				vIter	insertBegin = _vector.insertionOrder.begin();
				vIter	insertEnd = _vector.insertionOrder.end();

				if (std::find(insertBegin, insertEnd, jacob) == insertEnd)
					_vector.insertionOrder.push_back(jacob);

				jacob--;
			}
		}
		else {
			int missing = _vector.pend.size() - 1;

			while (_vector.insertionOrder.size() < _vector.pend.size())
				_vector.insertionOrder.push_back(missing--);
		}

	}
}

void	PmergeMe::insertInOrder(void) {
	vIter	insertBegin = _vector.insertionOrder.begin();
	vIter	insertEnd = _vector.insertionOrder.end();

	for (vIter it = insertBegin; it != insertEnd; it++) {
		int		value = _vector.pend[*it];
		vIter	position = std::upper_bound(_vector.main.begin(), _vector.main.end(), value);

		_vector.main.insert(position, value);
	}
}
