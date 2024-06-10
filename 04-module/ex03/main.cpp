/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:23 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 15:42:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

int main(void)
{
	game	game;

	introduction(game);
	battle(game);
	ending(game);

	return (EXIT_SUCCESS);
}
