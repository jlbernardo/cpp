/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/10 20:11:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
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

#endif
