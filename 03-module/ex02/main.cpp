/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 16:46:06 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

int	main(void) {

	constructionMessage();

	FragTrap unknown;
	FragTrap marvin("Marvin");
	FragTrap derp("Derp");
	FragTrap copy(derp);

	fight(marvin, derp);

	destructionMessage();
}
