/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:37:10 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:05:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Unknown"), _gem("❔") {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria(void) {
}

AMateria	&AMateria::operator=(const AMateria &copy) {
	if (this != &copy) {
		this->_type = copy.getType();
		this->_gem = copy.getGem();
	}
	return (*this);
}

void	AMateria::use(ICharacter &target) {
	(void)target;
}

void	AMateria::use(Character &target) {
	(void)target;
}

std::string const	&AMateria::getType() const {
	return (this->_type);
}

std::string const	&AMateria::getGem() const {
	return (this->_gem);
}
