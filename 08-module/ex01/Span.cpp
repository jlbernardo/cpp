/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:42:17 by julberna          #+#    #+#             */
/*   Updated: 2024/07/10 14:20:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int		rangeStart;		//Beginning of random number generator range
int		rangeEnd;		//Ending of random number generator range
bool	single = true;	//Specifies if addNumber is being called by addMany or not

Span::Span(void) : _sizeLimit(INT_MAX), _sizeCurrent(0),
	_shortestSpan(INT_MAX), _longestSpan(0),
	 _sh1(0), _sh2(0), _lo1(0), _lo2(0) {
}

Span::Span(int N) : _sizeLimit(N), _sizeCurrent(0),
	_shortestSpan(INT_MAX), _longestSpan(0),
	 _sh1(0), _sh2(0), _lo1(0), _lo2(0) {
}

Span::Span(const Span &copy) {
	*this = copy;
}

Span::~Span(void) {
}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		std::copy(rhs._content.begin(), rhs._content.end(),
			std::back_inserter(this->_content));
		this->_sizeLimit = rhs._sizeLimit;
		this->_sizeCurrent = rhs._sizeCurrent;
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (this->_sizeCurrent >= this->_sizeLimit)
		throw std::overflow_error("Size limit reached! Cannot add any more numbers.");
	this->_content.push_back(number);
	this->_sizeCurrent++;
	if (single)
		calculateSpans();
}

void	Span::addMany(int size) {
	single = false;
	for (int i = 0; i < size; i++)
		this->addNumber(0);
	this->randomFill(0, size * 100);
	single = true;
}

int		rangeRand(void) {
	int	value;

	value = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
	return (value);
}

void	Span::randomFill(int start, int end) {
	rangeStart = start;
	rangeEnd = end;
	std::generate(this->_content.begin(), this->_content.end(), rangeRand);
	this->_sizeCurrent = this->_sizeLimit;
	calculateSpans();
}

void	Span::print(void) {
	std::cout << WHT << "\n [";
	for (iterator it = this->_content.begin(); it != this->_content.end(); it++) {
		if (it != this->_content.begin())
			std::cout << ", ";
		if (*it == this->_lo1 || *it == this->_lo2)
			std::cout << GRN;
		if (*it == this->_sh1 || *it == this->_sh2)
			std::cout << RED;
		std::cout << *it << WHT;
	}
	println("]\n");
}

void	Span::calculateSpans(void) {

	std::sort(this->_content.begin(), this->_content.end());

	for (unsigned int i = 0; i < this->_content.size() - 1; i++) {
		int span = this->_content[i + 1] - this->_content[i];
		if (span > this->_longestSpan) {
			this->_longestSpan = span;
			this->_lo1 = this->_content[i];
			this->_lo2 = this->_content[i + 1];
		}
		if (span > 0 && span < this->_shortestSpan) {
			this->_shortestSpan = span;
			this->_sh1 = this->_content[i];
			this->_sh2 = this->_content[i + 1];
		}
	}
}

int		Span::longestSpan(void) const {
	if (this->_content.size() < 2)
		throw std::range_error("No span could be found!");
	return (this->_longestSpan);
}

int		Span::shortestSpan(void) const {
	if (this->_content.size() < 2)
		throw std::range_error("No span could be found!");
	return (this->_shortestSpan);
}

int		Span::lowerShortest(void) const {
	return (this->_sh1);
}

int		Span::upperShortest(void) const {
	return (this->_sh2);
}

int		Span::lowerLongest(void) const {
	return (this->_lo1);
}

int		Span::upperLongest(void) const {
	return (this->_lo2);
}
