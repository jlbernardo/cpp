/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/10 23:00:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <cmath>
# include <string>
# include <sstream>
# include <iomanip>
# include "general.hpp"

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename MutantStack::container_type::iterator iterator;
	typedef typename MutantStack::container_type::reverse_iterator reverse_iterator;

						MutantStack(void) : std::stack<T>() {}
						~MutantStack(void) {}
	MutantStack			&operator=(const MutantStack &rhs) {
							std::stack<T>::operator=(rhs);
							return (*this);
						}
						MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}

	iterator			begin(void) { return (this->c.begin()); }
	iterator			end(void) { return (this->c.end()); }
	reverse_iterator	rbegin(void) { return (this->c.rbegin()); }
	reverse_iterator	rend(void) { return (this->c.rend()); }
};

template <typename T>
int						longerNumber(MutantStack<T> &rhs) {
	unsigned int	longest = 0;

	for (typename MutantStack<T>::iterator it = rhs.begin(); it != rhs.end(); ++it) {
		std::stringstream	ss;

		ss << *it;
		if (ss.str().length() > longest)
			longest = ss.str().length();
	}
	return (longest);
}

template <typename T>
std::string	getTop(MutantStack<T> &rhs) {
	std::stringstream ss;

	ss << rhs.top();
	return (ss.str());
}

template <typename T>
std::ostream			&operator<<(std::ostream &o, MutantStack<T> &rhs) {
	int	width = longerNumber(rhs);
	o << WHT << " stack: ╭ " << std::setw(width + 5) << " ╮\n";
	for (typename MutantStack<T>::reverse_iterator it = rhs.rbegin(); it != rhs.rend(); ++it) {

		o << "        │ " << std::setw(width) << *it << " │" << std::endl;
	}
	o << "        ╰ " << std::setw(width + 4) << " ╯" << std::endl;

	std::stringstream	ss;

	o << "   top: " << (rhs.empty() ? RED + std::string("empty") : GRN + getTop(rhs));
	o << WHT << std::endl;
	o << "  size: " << PRP << rhs.size() << std::endl;
	return (o);
}

#endif
