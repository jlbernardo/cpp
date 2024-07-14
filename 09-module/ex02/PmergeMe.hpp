/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:52:00 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 21:22:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PPMERGEME_HPP

# include <ctime>
# include <deque>
# include <vector>
# include <algorithm>
# include "general.hpp"

template <typename T>
struct sort {
	T				c;
	std::clock_t	time;
};

class PmergeMe {

private:
	int							_size;
	std::vector<int>			_input;
	sort< std::vector<int> >	_vector;
	sort< std::deque<int> >		_deque;

				PmergeMe(void);
				PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &rhs);

	void		validateInput(char **argv);
	void		validateUniqueness(void);
	void		populateContainers(void);

	void		dequeSort(void);
	void		vectorSort(void);

	void		print(void);

public:
				PmergeMe(char **argv);
				~PmergeMe(void);
};

#endif
