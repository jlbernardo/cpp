/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:23 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 15:57:58 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

int main(void)
{
	game	game;

	loadGame(game);
	introduction(game);
	gameStart(game);
	gameOver(game);
	return (EXIT_SUCCESS);
}
