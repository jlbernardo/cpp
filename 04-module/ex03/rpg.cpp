/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:07:11 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 21:11:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	introduction(game &game) {
	getName(game);
	getType(game);
}

void	gameStart(game &game) {
	fight(*game.me, *game.azrael);
	aftermath(game, *game.azrael);
	fight(*game.me, *game.evanora);
	aftermath(game, *game.evanora);
	fight(*game.me, *game.ghidorah);
	aftermath(game, *game.ghidorah);
}
