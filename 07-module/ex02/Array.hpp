/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:43:04 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 19:40:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "iter.hpp"
# include "general.hpp"
# include <exception>

template<typename T>
class Array {
private:
	std::size_t	_size;
	T			*_content;

public:
				Array(void) : _size(0), _content(new T[_size]) {}
				Array(std::size_t n) : _size(n), _content(new T[n]) {}

				~Array(void) {
					delete [] this->_content;
				}

				Array(const Array &copy) : _size(0), _content(NULL) {
					*this = copy;
				}

	Array		&operator=(const Array &rhs) {
					if (this != &rhs) {
						if (this->_size)
							delete [] this->_content;
						this->_size = rhs.size();
						if (rhs.size() > 0)
							this->_content = new T[rhs.size()];
						for (std::size_t i = 0; i < rhs.size(); i++)
							this->_content[i] = rhs[i];
					}
					return (*this);
				}

	T			&operator[](std::size_t idx) {
					if (idx < 0 || idx > this->_size - 1)
						throw std::out_of_range("Index out of bounds!");
					return (this->_content[idx]);
				}

	const T		&operator[](std::size_t idx) const {
					if (idx < 0 || idx > this->_size - 1)
						throw std::out_of_range("Index out of bounds!");
					return (this->_content[idx]);
				}

	std::size_t	size(void) const { return (this->_size); }
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &arr) {
	for (std::size_t i = 0; i < arr.size() - 1; i++)
		o << static_cast<T>(arr[i]) << " ";
	return (o);
}

#endif
