/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:30 by julberna          #+#    #+#             */
/*   Updated: 2024/05/07 22:37:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <fstream>
# include <iostream>
# include "general.hpp"

# define DEBUG			0
# define INFO			1
# define WARNING		2
# define ERROR			3
# define MAX_OPTIONS	4

class Harl {

public:
	void	complain(std::string level);

private:
	void	info(void);
	void	debug(void);
	void	error(void);
	void	warning(void);
};

void	bubble(std::string file);
int		verification(int argc, char **argv);

#endif
