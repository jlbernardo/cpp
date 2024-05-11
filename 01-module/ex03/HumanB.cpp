/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:41:26 by julberna          #+#    #+#             */
/*   Updated: 2024/05/11 15:50:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
	println(GRN << "\n👶 " << this->_name << " was born. 👶\n" << DFL);
}

HumanB::~HumanB(void) {
	println(YLW << "\n⚰️  " << this->_name << " is now deceased. ⚰️\n" << DFL);
}

void	HumanB::attack(void) {
	if (this->_weapon == NULL) {
		println(WHT << this->_name << RED << " attacks" <<
			WHT << " with their bare hands! 👊" << DFL);
	}
	else {
		println(WHT << this->_name << RED << " attacks" <<
			WHT << " with their " << this->_weapon->getType() << "! ⚔️" << DFL);
	}
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
