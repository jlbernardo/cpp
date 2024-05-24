/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/05/24 17:06:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void) {

	srand(time(NULL));
	constructionMessage();

	ClapTrap unknown;
	ClapTrap marvin("Marvin");
	ClapTrap hactar("Hactar");
	ClapTrap copy(hactar);

	fight(marvin, hactar);

	destructionMessage();
}
