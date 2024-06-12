/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dark.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:07 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:26:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dark.hpp"

Dark::Dark(void) : AMateria("Dark") {
	this->_gem = "🌑";
}

Dark::Dark(Dark const &copy) : AMateria(copy) {
}

Dark::~Dark(void) {
}

Dark	&Dark::operator=(Dark const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria	*Dark::clone(void) const {
	return (new Dark(*this));
}

void	Dark::use(ICharacter &target) {
	println(PRP << "* sucks life out of " << target.getName() << "'s body *");
}

void	Dark::use(Character &target) {
	println(PRP << "* sucks life out of " << target.getName() << "'s body *");
	srand(time(NULL));
	int	amount = rand() % 20 + 30;
	target.modHealth(-amount);
}
