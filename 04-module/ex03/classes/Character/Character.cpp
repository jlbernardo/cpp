/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:40:21 by julberna          #+#    #+#             */
/*   Updated: 2024/06/08 23:30:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _health(PHASE1_HP) {
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

Character::Character(void) : _name("Lone Wolf"), _health(PHASE1_HP) {
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

Character::Character(Character const &other) {
	*this = other;
}

Character::~Character(void) {
	for (int i = 0; i < MAX_MATERIA; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

Character	&Character::operator=(Character const &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (this->_materia[i])
				delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_MATERIA || !this->_materia[idx])
		return ;
	this->_materia[idx] = NULL;
}

void	Character::equip(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (!this->_materia[i]) {
			this->_materia[i] = m;
			break ;
		}
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_MATERIA || !this->_materia[idx])
		return ;
	this->_materia[idx]->use(target);
}

std::string const	&Character::getName(void) const {
	return (this->_name);
}

unsigned int const	&Character::getHealth(void) const {
	return (this->_health);
}

std::string const	Character::getMateriaGem(int idx) const {
	if (idx < 0 || idx >= MAX_MATERIA || !this->_materia[idx])
		return ("◾");
	return (this->_materia[idx]->getGem());
}

std::string const	Character::getMateriaType(int idx) const {
	if (idx < 0 || idx >= MAX_MATERIA || !this->_materia[idx])
		return ("Empty");
	return (this->_materia[idx]->getType());
}

AMateria	*Character::getMateria(int idx) const {
	if (idx < 0 || idx >= MAX_MATERIA || !this->_materia[idx])
		return (NULL);
	return (this->_materia[idx]);
}

void	Character::modHealth(int amount) {
	if (amount < 0) {
		for (int i = amount; i <= 0; i++) {
			if (this->_health == 0)
				break ;
			this->_health--;
		}
	}
	else
		this->_health += amount;
}

void	Character::setHealth(unsigned int amount) {
	this->_health = amount;
}
