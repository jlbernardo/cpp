/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:13:58 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 19:53:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	println(GRN << this->_name << ": raised from the dead!" << DFL);
}

Zombie::~Zombie (void) {
	println(RED << this->_name << ": died of mysterious causes." << DFL );
}

void	Zombie::announce(void) {
	println(YLW << this->_name << ": BraiiiiiiinnnzzzZ..." << DFL);
}
