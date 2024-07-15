/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   setd: 2024/07/13 20:28:03 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 06:42:49 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::dequeSort(void) {

	std::deque<intPair>	pairs;

	_deque.time = clock();

	setOddElement();
	setSortedPairs(pairs);
	setMainAndPend(pairs);
	setJacobsthalNumbers();
	setInsertionOrder();
	placeInOrder();

	_deque.time = (clock() - _deque.time) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::setOddElement(void) {
	_deque.odd = -1;

	if (_deque.c.size() % 2 != 0) {
		_deque.odd = _deque.c.back();
		_deque.c.pop_back();
	}
}

void	PmergeMe::setSortedPairs(dPair &pairs) {

	for (dIter it = _deque.c.begin(); it < _deque.c.end(); it += 2) {

		intPair		pair(*it, *(it + 1));

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);

		pairs.push_back(pair);
	}

	std::sort(pairs.begin(), pairs.end());
}

void	PmergeMe::setMainAndPend(dPair &pairs) {

	for (dPairIter it = pairs.begin(); it != pairs.end(); it++)
		_deque.main.push_back(it->first);

	for (dPairIter it = pairs.begin(); it != pairs.end(); it++)
		_deque.pend.push_back(it->second);

	if (_deque.odd != -1)
		_deque.pend.push_back(_deque.odd);
}

void	PmergeMe::setJacobsthalNumbers(void) {

	_deque.jacobsthal.push_back(0);
	_deque.jacobsthal.push_back(1);

	int nextNumber = *(_deque.jacobsthal.end() - 2) * 2 + _deque.jacobsthal.back();

	while (nextNumber < static_cast<int>(_deque.pend.size() - 1)) {
		_deque.jacobsthal.push_back(nextNumber);
		nextNumber = *(_deque.jacobsthal.end() - 2) * 2 + _deque.jacobsthal.back();
	}

	_deque.jacobsthal.erase(_deque.jacobsthal.begin() + 1);
}

void	PmergeMe::setInsertionOrder(void) {

	_deque.insertionOrder.push_back(_deque.jacobsthal.front());

	while (_deque.insertionOrder.size() < _deque.pend.size()) {
		_deque.jacobsthal.erase(_deque.jacobsthal.begin());

		if (!_deque.jacobsthal.empty()) {
			int	last = _deque.insertionOrder.back();
			int	jacob  = _deque.jacobsthal.front();

			_deque.insertionOrder.push_back(jacob--);
			while (jacob > last && _deque.insertionOrder.size() < _deque.pend.size()) {
				dIter	insertBegin = _deque.insertionOrder.begin();
				dIter	insertEnd = _deque.insertionOrder.end();

				if (std::find(insertBegin, insertEnd, jacob) == insertEnd)
					_deque.insertionOrder.push_back(jacob);

				jacob--;
			}
		}
		else {
			int missing = _deque.pend.size() - 1;

			while (_deque.insertionOrder.size() < _deque.pend.size())
				_deque.insertionOrder.push_back(missing--);
		}

	}
}

void	PmergeMe::placeInOrder(void) {
	dIter	insertBegin = _deque.insertionOrder.begin();
	dIter	insertEnd = _deque.insertionOrder.end();

	for (dIter it = insertBegin; it != insertEnd; it++) {
		int		value = _deque.pend[*it];
		dIter	position = std::upper_bound(_deque.main.begin(), _deque.main.end(), value);

		_deque.main.insert(position, value);
	}
}
