/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:39 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:26:32 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

Fire::Fire(void) : AMateria("Fire") {
	this->_gem = "🔥";
}

Fire::Fire(Fire const &copy) : AMateria(copy) {
}

Fire::~Fire(void) {
}

#include "ICharacter.hpp"

Fire	&Fire::operator=(Fire const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria	*Fire::clone(void) const {
	return (new Fire(*this));
}

void	Fire::use(ICharacter &target) {
	println(RED << "* casts a fire ball in " << target.getName() << "'s direction *");
}

void	Fire::use(Character &target) {

	println(RED << "* casts a fire ball in " << target.getName() << "'s direction *");
	srand(time(NULL));
	int	amount = rand() % 20 + 5;
	target.modHealth(-amount);
}
