/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:52:00 by julberna          #+#    #+#             */
/*   Updated: 2024/07/15 04:00:34 by julberna         ###   ########.fr       */
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

template <typename Container>
struct sort {
	Container		c;
	Container		main;
	Container		pend;
	std::clock_t	time;
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

	void		validateInput(char **argv);
	void		validateUniqueness(void);
	void		populateContainers(void);

	void		dequeSort(void);
	void		vectorSort(void);

public:
				PmergeMe(char **argv);
				~PmergeMe(void);

	void		calculate(void);
	void		print(void);
};


#endif
