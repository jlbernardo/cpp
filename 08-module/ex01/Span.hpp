/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:41:55 by julberna          #+#    #+#             */
/*   Updated: 2024/07/10 13:44:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <limits>
# include <unistd.h>
# include <experimental/random>
# include <algorithm>
# include "general.hpp"

# define INT_MAX std::numeric_limits<int>::max()

typedef std::vector<int>::iterator iterator;

class Span {

private:
	std::vector<int>	_content;
	unsigned int		_sizeLimit;
	unsigned int		_sizeCurrent;
	int					_shortestSpan;
	int					_longestSpan;
	int					_sh1;
	int					_sh2;
	int					_lo1;
	int					_lo2;

	void				calculateSpans(void);

public:
						Span(void);
						Span(int N);
						~Span(void);
						Span(const Span &copy);
	Span				&operator=(const Span &rhs);

	void				addMany(int size);
	void				addNumber(int number);
	int					longestSpan(void) const;
	int					shortestSpan(void) const;
	int					lowerShortest(void) const;
	int					upperShortest(void) const;
	int					lowerLongest(void) const;
	int					upperLongest(void) const;
	void				randomFill(int start, int end);
	void				print(void);
};

#endif
