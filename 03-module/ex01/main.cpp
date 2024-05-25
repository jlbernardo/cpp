/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 19:55:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void) {

	srand(time(NULL));
	constructionMessage();

	ScavTrap unknown;
	ScavTrap marvin("Marvin");
	ScavTrap colin("Colin");
	ScavTrap copy(colin);

	fight(marvin, colin);

	destructionMessage();
}
