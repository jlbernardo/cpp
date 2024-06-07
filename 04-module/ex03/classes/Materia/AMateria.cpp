/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:37:10 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 23:13:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Unknown"), _gem("❔") {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria(void) {
}

void	AMateria::use(ICharacter &target) {
	(void)target;
}

std::string const	&AMateria::getType() const {
	return (this->_type);
}

std::string const	&AMateria::getGem() const {
	return (this->_gem);
}
