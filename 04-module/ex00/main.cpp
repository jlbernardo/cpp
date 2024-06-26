/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:19:10 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 21:15:02 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

int main(void) {

	testAnimalBaseClass();
	testCatClass();
	testDogClass();
	testWrongAnimalClass();
	testWrongCatClass();

	return (EXIT_SUCCESS);
}
