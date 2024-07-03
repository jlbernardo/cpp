/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 01:38:30 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 03:17:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Fixed.hpp"
#include "Cat.hpp"

int main(void) {
	std::size_t		size = 20;

	Array<int>		a(size);
	Array<int>		b(size);

	int x = 0, y = 1, z;

	for (std::size_t i = 0; i < size; i++) {
		a[i] = x;
		z = x + y;
		x = y;
		y = z;
		b[i] = x * 3;
	}

	println(WHT << "\n   Now we can create and manipulate arrays of any kind:\n");
	println(WHT << " int a: " << YLW << a);
	println(WHT << " int b: " << BLU << b);
	println("");

	Array<int>		c(a);
	println(WHT << "  c(a): " << YLW << c);

	c = b;
	b = a;
	println(WHT << " c = b: " << BLU << c);

	next;

	Array<char>		d(size + size);
	Array<Fixed>	e(size - 2);
	Array<Cat>		f(size);

	for (std::size_t i = 0; i < size + size; i++)
		d[i] = 'A' + i;

	for (std::size_t i = 0; i < size - 2; i++)
		e[i] = i + 0.5f;

	println(WHT << "   Really... " << RED << "ANY" << WHT << " kind!\n");
	println(WHT << "  chars: " << YLW << d);
	println(WHT << "  fixed: " << BLU << e);
	println(WHT << "   cats: " << GRN << f);
}
