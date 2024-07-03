/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:06:41 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 03:56:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"

int main(void){
	int tab[] = {0, 1, 2, 3, 4};

	println(WHT << "\n Now we have the " << RED << "iter" << WHT << " function."
				<< " It can be user with arrays of any kind");
	println(WHT << " and applies a function to each element. Here, we are adding 5 to each element.");
	std::cout << PRP << "   ";
	::iter(tab, 5, print);
	std::cout << RED;
	::iter(tab, 5, plusFive<int>);

	println("\n");


	println(WHT << " And, again, it can be a char:");
	std::cout << PRP << "   ";
	char teb[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(teb, 5, print);
	std::cout << RED;
	::iter(teb, 5, plusFive<char>);

	println("\n");

	println(WHT << " Or any other custom type we create, like our good'ol Fixed:");
	std::cout << PRP << "   ";
	Fixed tib[] = {Fixed(1.1f), Fixed(2.2f), Fixed(3.3f), Fixed(4.4f), Fixed(5.55f)};
	::iter(tib, 5, print);
	std::cout << RED;
	::iter(tib, 5, plusFive<Fixed>);
	println("");
}

