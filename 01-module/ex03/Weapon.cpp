/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:24:07 by julberna          #+#    #+#             */
/*   Updated: 2024/05/08 12:07:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	println(BLU << "~ " << this->_type << " created ~" << DFL);
}

Weapon::~Weapon(void) {
	println(PRP << "~ " << this->_type << " is now destroyed ~" << DFL);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}

std::string const	Weapon::getType(void) const {
	return (this->_type);
}
