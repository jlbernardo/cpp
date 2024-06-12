/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:07 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:22:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure") {
	this->_gem = "💓";
}

Cure::Cure(Cure const &copy) : AMateria(copy) {
}

Cure::~Cure(void) {
}

Cure	&Cure::operator=(Cure const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria	*Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	println(GRN << "* heals " << target.getName() << "'s wounds *");
}

void	Cure::use(Character &target) {
	println(GRN << "* heals " << target.getName() << "'s wounds *");
	srand(time(NULL));
	int	amount = rand() % 10 + 10;
	target.modHealth(amount);
}
