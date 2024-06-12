/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 20:16:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Thunder.hpp"

Thunder::Thunder(void) : AMateria("Thunder") {
	this->_gem = "⚡";
}

Thunder::Thunder(Thunder const &other) : AMateria(other) {
}

Thunder::~Thunder(void) {
}

#include "ICharacter.hpp"

Thunder	&Thunder::operator=(Thunder const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria	*Thunder::clone(void) const {
	return (new Thunder(*this));
}

void	Thunder::use(ICharacter &target) {
	println(YLW << "* shoots a thunder bolt at " << target.getName() << " *");
}

void	Thunder::use(Character &target) {

	println(YLW << "* shoots a thunder bolt at " << target.getName() << " *");
	srand(time(NULL));
	int	amount = rand() % 20 + 20;
	target.modHealth(-amount);
}
