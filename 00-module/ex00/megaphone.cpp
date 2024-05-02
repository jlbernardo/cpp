/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:05:13 by julberna          #+#    #+#             */
/*   Updated: 2024/04/29 21:54:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (std::string::iterator it = str.begin(); it != str.end(); it++)
				std::cout << (char)toupper(*it);
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
