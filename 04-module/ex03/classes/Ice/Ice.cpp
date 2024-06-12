/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:28:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice") {
	this->_gem = "❄️ ";
}

Ice::Ice(Ice const &copy) : AMateria(copy) {
}

Ice::~Ice(void) {
}

#include "ICharacter.hpp"

Ice	&Ice::operator=(Ice const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria	*Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	println(CYN << "* shoots an ice bolt at " << target.getName() << " *");
}

void	Ice::use(Character &target) {

	println(CYN << "* shoots an ice bolt at " << target.getName() << " *");
	srand(time(NULL));
	int	amount = rand() % 10 + 10;
	target.modHealth(-amount);
}
