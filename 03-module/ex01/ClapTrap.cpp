/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:09:19 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 16:04:55 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknown"), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
	println(GRN << "     ClapTrap constructor called for " << this->_name << ".");
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10) {
	println(GRN << "     ClapTrap constructor called for " << this->_name << ".");
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	println(GRN << "     ClapTrap copy constructor called for " << copy._name << ".");
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	println(RED << "     ClapTrap destructor called for " << this->_name << ".");
}

void	ClapTrap::operator=(const ClapTrap &copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " attacks " << target
					<< ", causing " << this->_attackDamage << " points of damage!");
		this->_energyPoints--;
	}
	if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " doesn't has enough energy points to attack.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is already dead and cannot attack.");
	}

}

void	ClapTrap::attack(ClapTrap &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && target.getHitPoints() > 0) {
		println(WHT << "       " << this->_name << " attacks " << target._name
					<< ", causing " << this->_attackDamage << " points of damage!");
		target.takeDamage(this->_attackDamage);
		this->_energyPoints--;
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " doesn't has enough energy points to attack.\n");
	}
	else if (target.getHitPoints() <= 0) {
		println(WHT << "       " << target._name << " is already dead. Let's not violate the corpse.\n");
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is already dead and cannot attack.\n");
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	total = 0;
	if (this->_hitPoints > 0) {
		while (amount > 0 && this->_hitPoints > 0) {
			this->_hitPoints--;
			amount--;
			total++;
		}
		println(WHT << "       " << this->_name << " takes " << total << " points of damage!");
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " repaires " << amount << " points to its health.");
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " doesn't has enough energy points to repair itself.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is already dead. Too late to try and heal.");
	}
}

void	ClapTrap::upgrade(void) {

	int		points= rand() % 20;

	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << "Engaging... " << this->_name << " gains " << points << " points of damage.");
		this->_energyPoints--;
		this->_attackDamage += points;
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " doesn't has enough energy points to upgrade itself.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is already dead. It is just a pile of rust now.");
	}
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

std::string	ClapTrap::getName(void) const {
	return this->_name;
}
