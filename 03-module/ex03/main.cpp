/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 17:01:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

int	main(void) {

	constructionMessage();

	DiamondTrap unknown;
	DiamondTrap marvin("Marvin");
	DiamondTrap shiny("Shiny");
	DiamondTrap copy(shiny);

	fight(marvin, shiny);

	destructionMessage();
}
