/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:02:12 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 21:00:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void) {

	srand(time(NULL));
	constructionMessage();

	FragTrap unknown;
	FragTrap marvin("Marvin");
	FragTrap derp("Derp");
	FragTrap copy(derp);

	fight(marvin, derp);

	destructionMessage();
}
