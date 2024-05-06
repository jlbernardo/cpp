/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:36:44 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 20:58:06 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	int		N = 5;
	Zombie	*horde;

	println("Creating a horde of zombies (they'll be named after this):");
	horde = zombieHorde(N, "Jim");

	println("\nAre they all there and alive?");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	println("\nTime to say goodbye...");
	delete [] horde;
}
