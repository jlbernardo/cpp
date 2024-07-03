/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:06:41 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 00:40:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"

int main(void){
	int tab[] = {0, 1, 2, 3, 4};
	::iter(tab, 5, print);
	::iter(tab, 5, plusFive<int>);

	println("");

	char teb[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(teb, 5, print);
	::iter(teb, 5, plusFive<char>);

	println("");

	Fixed tib[] = {Fixed(1.1f), Fixed(2.2f), Fixed(3.3f), Fixed(4.4f), Fixed(5.55f)};
	::iter(tib, 5, print);
	::iter(tib, 5, plusFive<Fixed>);
}

