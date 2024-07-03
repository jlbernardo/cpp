/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:06:41 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 03:26:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"

int main(void){
	int tab[] = {0, 1, 2, 3, 4};

	println(WHT << "\n We can iterate over an array of any type and apply any function to it:");
	std::cout << PRP << "   ";
	::iter(tab, 5, print);
	std::cout << RED;
	::iter(tab, 5, plusFive<int>);

	println("\n");


	println(WHT << " It can be a char array:");
	std::cout << PRP << "   ";
	char teb[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(teb, 5, print);
	std::cout << RED;
	::iter(teb, 5, plusFive<char>);

	println("\n");

	println(WHT << " Or any other custom type we create, like the Fixed points from another list:");
	std::cout << PRP << "   ";
	Fixed tib[] = {Fixed(1.1f), Fixed(2.2f), Fixed(3.3f), Fixed(4.4f), Fixed(5.55f)};
	::iter(tib, 5, print);
	std::cout << RED;
	::iter(tib, 5, plusFive<Fixed>);
	println("");
}

