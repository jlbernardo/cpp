/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:36:44 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 20:13:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	*z1;

	println("Call to randomChump():");
	randomChump("Gabriel");

	println("\nCall to newZombie():");
	z1 = newZombie("Charlie");
	z1->announce();
	delete z1;
}
