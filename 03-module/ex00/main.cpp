/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:27:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

int	main(void) {

	constructionMessage();

	ClapTrap unknown;
	ClapTrap marvin("Marvin");
	ClapTrap hactar("Hactar");
	ClapTrap copy(hactar);

	fight(marvin, hactar);

	destructionMessage();
}
