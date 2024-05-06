/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:41 by julberna          #+#    #+#             */
/*   Updated: 2024/05/05 23:06:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	println(GRN << "\n👶 " << this->_name << " was born. 👶\n" << DFL);
}

HumanA::~HumanA(void) {
	println(YLW << "\n🪦  " << this->_name << " was killed mercilessly. 🪦\n" << DFL);
}

void	HumanA::attack(void) {
	println(WHT << this->_name << RED << " attacks" <<
			WHT << " with their " << this->_weapon.getType() << "! ⚔️" << DFL);
}
