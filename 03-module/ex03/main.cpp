/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 17:42:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void) {

	srand(time(NULL));
	constructionMessage();

	DiamondTrap unknown;
	DiamondTrap marvin("Marvin");
	DiamondTrap shiny("Shiny");
	DiamondTrap copy(shiny);

	fight(marvin, shiny);

	destructionMessage();
}
