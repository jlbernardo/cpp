/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dark.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:07 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 15:15:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dark.hpp"

Dark::Dark(void) : AMateria("Dark") {
	this->_gem = "🌑";
}

Dark::Dark(Dark const &other) : AMateria(other) {
}

Dark::~Dark(void) {
}

Dark	&Dark::operator=(Dark const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria	*Dark::clone(void) const {
	return (new Dark(*this));
}

void	Dark::use(ICharacter &target) {

	println(PRP << "* sucks life out of " << target.getName() << "'s body *");

	srand(time(NULL));
	int	amount = rand() % 20 + 30;
	target.modHealth(-amount);
}
