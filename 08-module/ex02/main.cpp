/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:33:36 by julberna          #+#    #+#             */
/*   Updated: 2024/07/10 23:22:10 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int>	mstack;
	int					i = 0;
	int					values[] = {5, 17, 42, 3, 5, 73, 0};

	println(WHT << "\n   First, we create a Mutant empty stack:\n");
	println(mstack);

	next;

	println(WHT << "   Then, we can push some numbers to it, like " << values[i] << ":\n");
	mstack.push(values[i++]);
	println(mstack);

	next;

	println(WHT << "   Can also push a " << values[i] << ":\n");
	mstack.push(values[i++]);
	println(mstack);

	next;

	for (int j = i; j < 7; j++) {
		println(WHT << "   And a bunch of others:\n");
		mstack.push(values[i++]);
		println(mstack);

		next;
	}

	for (int j = 0; j < 3; j++) {
		println(WHT << "   We can also pop numbers, removing them from the top:\n");
		mstack.pop();
		println(mstack);

		next;
	}

	println(WHT << "   At last, as with any canonical class, we can create");
	println(WHT << "   copies with constructors or assignement operators:\n");
	MutantStack<int>	copy(mstack);
	MutantStack<int>	assigned;

	assigned = copy;

	println(CYN << " ORIGINAL\n" << mstack);
	println(CYN << " COPY\n" << copy);
	println(CYN << " ASSIGNED\n" << assigned);
	return 0;
}
