/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:40:03 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 04:44:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::vectorSort(void) {
	this->_vector.time = clock();

	std::vector<intPair>	pairs;
	int						straggler = -1;

	if (this->_vector.c.size() % 2 != 0) {
		straggler = this->_vector.c.back();
		this->_vector.c.pop_back();
	}

	for (vIter it = this->_vector.c.begin(); it < this->_vector.c.end(); it += 2) {

		intPair		pair(*it, *(it + 1));

		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);

		pairs.push_back(pair);
	}

	std::sort(pairs.begin(), pairs.end());

	for (vPairIter it = pairs.begin(); it != pairs.end(); it++)
		this->_vector.main.push_back(it->first);

	for (vPairIter it = pairs.begin(); it != pairs.end(); it++)
		this->_vector.pend.push_back(it->second);

	if (straggler != -1)
		this->_vector.pend.push_back(straggler);

	std::vector<int>	jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	int j = *(jacobsthal.end() - 2) * 2 + jacobsthal.back();
	while (j < static_cast<int>(this->_vector.pend.size() - 1)) {
		jacobsthal.push_back(j);
		j = *(jacobsthal.end() - 2) * 2 + jacobsthal.back();
	}

	jacobsthal.erase(jacobsthal.begin() + 1);

	std::vector<int>	insertionOrder;
	insertionOrder.push_back(jacobsthal.front());

	while (insertionOrder.size() < this->_vector.pend.size()) {
		jacobsthal.erase(jacobsthal.begin());

		if (!jacobsthal.empty()) {
			int	last = insertionOrder.back();
			int	jacob  = jacobsthal.front();

			insertionOrder.push_back(jacob--);
			while (jacob > last && insertionOrder.size() < this->_vector.pend.size()) {
				if (std::find(insertionOrder.begin(), insertionOrder.end(), jacob) == insertionOrder.end())
					insertionOrder.push_back(jacob);
				jacob--;
			}
		}
		else {
			int missing = this->_vector.pend.size() - 1;

			while (insertionOrder.size() < this->_vector.pend.size())
				insertionOrder.push_back(missing--);
		}

	}

	for (vIter it = insertionOrder.begin(); it != insertionOrder.end(); it++) {
		int		value = this->_vector.pend[*it];
		vIter	position = std::upper_bound(this->_vector.main.begin(), this->_vector.main.end(), value);

		this->_vector.main.insert(position, value);
	}

	this->_vector.time = (clock() - this->_vector.time) * 1000000.0 / CLOCKS_PER_SEC;
}
