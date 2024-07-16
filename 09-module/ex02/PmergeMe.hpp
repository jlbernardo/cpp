/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:52:00 by julberna          #+#    #+#             */
/*   Updated: 2024/07/16 20:41:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PPMERGEME_HPP

# include <ctime>
# include <deque>
# include <vector>
# include <iomanip>
# include <algorithm>
# include "general.hpp"

typedef std::deque<int>::iterator		dIter;
typedef std::vector<int>::iterator		vIter;
typedef std::pair<int, int> 			intPair;
typedef std::deque<intPair>::iterator	dPairIter;
typedef std::vector<intPair>::iterator	vPairIter;
typedef std::vector<int>				vInt;
typedef std::vector<intPair>			vPair;
typedef std::deque<int>					dInt;
typedef std::deque<intPair>				dPair;

template <typename Container>
struct sort {
	int				odd;
	Container		c;
	Container		main;
	Container		pend;
	std::clock_t	time;
	Container		jacobsthal;
	Container		insertionOrder;
};

class PmergeMe {

private:
	int								_size;
	std::vector<int>				_input;
	sort< std::vector<int> >		_vector;
	sort< std::deque<int> >			_deque;

				PmergeMe(void);
				PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &rhs);

	bool		notSorted(void);
	void		validateInput(char **argv);
	void		validateUniqueness(void);
	void		populateContainers(void);

	void		dequeSort(void);
	void		setOddElement(void);
	void		setSortedPairs(dPair &pairs);
	void		setMainAndPend(dPair &pairs);
	void		setJacobsthalNumbers(void);
	void		setInsertionOrder(void);
	void		placeInOrder(void);

	void		vectorSort(void);
	void		createOddElement(void);
	void		createSortedPairs(vPair &pairs);
	void		createMainAndPend(vPair &pairs);
	void		createJacobsthalNumbers(void);
	void		createInsertionOrder(void);
	void		insertInOrder(void);

public:
				PmergeMe(char **argv);
				~PmergeMe(void);

	void		calculate(void);
	void		print(void);
};


#endif
