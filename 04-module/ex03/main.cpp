/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:23 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 22:36:27 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int main(void)
{
	Game	game;

	game.introduction();
	game.battle();
	game.ending();

	return (EXIT_SUCCESS);
}
