/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:28:03 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 04:01:18 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::dequeSort(void) {
	this->_deque.time = clock();

	std::deque<intPair>	pairs;
	int						straggler = -1;

	// std::cout << RED << std::endl << "   Original: " << std::flush;
	// for (dIter it = this->_deque.c.begin(); it != this->_deque.c.end(); it++)
	// 	std::cout << *it << " ";
	// println("");

	if (this->_deque.c.size() % 2 != 0) {
		straggler = this->_deque.c.back();
		this->_deque.c.pop_back();
	}

	for (dIter it = this->_deque.c.begin(); it < this->_deque.c.end(); it += 2) {

		intPair		pair(*it, *(it + 1));

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);

		pairs.push_back(pair);
	}

	std::sort(pairs.begin(), pairs.end());

	for (dPairIter it = pairs.begin(); it != pairs.end(); it++)
		this->_deque.main.push_back(it->first);

	for (dPairIter it = pairs.begin(); it != pairs.end(); it++)
		this->_deque.pend.push_back(it->second);

	if (straggler != -1)
		this->_deque.pend.push_back(straggler);

	std::deque<int>	jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	int j = *(jacobsthal.end() - 2) * 2 + jacobsthal.back();
	while (j < static_cast<int>(this->_deque.pend.size() - 1)) {
		jacobsthal.push_back(j);
		j = *(jacobsthal.end() - 2) * 2 + jacobsthal.back();
	}

	jacobsthal.erase(jacobsthal.begin() + 1);

	std::deque<int>	insertionOrder;
	insertionOrder.push_back(jacobsthal.front());

	while (insertionOrder.size() < this->_deque.pend.size()) {
		jacobsthal.erase(jacobsthal.begin());

		if (!jacobsthal.empty()) {
			int	last = insertionOrder.back();
			int	jacob  = jacobsthal.front();

			insertionOrder.push_back(jacob--);
			while (jacob > last && insertionOrder.size() < this->_deque.pend.size()) {
				if (std::find(insertionOrder.begin(), insertionOrder.end(), jacob) == insertionOrder.end())
					insertionOrder.push_back(jacob);
				jacob--;
			}
		}
		else {
			int missing = this->_deque.pend.size() - 1;

			while (insertionOrder.size() < this->_deque.pend.size())
				insertionOrder.push_back(missing--);
		}

	}

	for (dIter it = insertionOrder.begin(); it != insertionOrder.end(); it++) {
		int		value = this->_deque.pend[*it];
		dIter	position = std::upper_bound(this->_deque.main.begin(), this->_deque.main.end(), value);

		this->_deque.main.insert(position, value);
	}

	// std::cout << YLW << std::endl << "     Sorted? " << std::flush;
	// for (dIter it = this->_deque.main.begin(); it != this->_deque.main.end(); it++)
	// 	std::cout << *it << " ";
	// println("\n");

	// this->_deque.time = (clock() - this->_deque.time) * 1000000.0 / CLOCKS_PER_SEC;
	// println(GRN << "       Time: " << std::fixed << std::setprecision(4) << this->_deque.time << "μs");
}
