/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:45:59 by julberna          #+#    #+#             */
/*   Updated: 2024/05/25 20:02:30 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_keeperMode = false;
	println(CYN << "     ScavTrap constructor called for " << this->_name << ".");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_keeperMode = false;
	println(CYN << "     ScavTrap constructor called for " << this->_name << ".");
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy) {
	this->_keeperMode = false;
	println(CYN << "     ScavTrap copy constructor called for " << this->_name << ".");
}

ScavTrap::~ScavTrap(void) {
	println(PRP << "     ScavTrap destructor called for " << this->_name << ".");
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " strikes " << target << ", " << this->_attackDamage << " points of damage dealt.");
		this->_energyPoints--;
	}
	if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " is too tired to attack, there's no energy left.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is unresponsive. Cannot attack.");
	}
}

void	ScavTrap::attack(ScavTrap &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && target.getHitPoints() > 0) {
		println(WHT << "       " << this->_name << " strikes " << target._name << ", " << this->_attackDamage << " points of damage dealt.");
		target.takeDamage(this->_attackDamage);
		this->_energyPoints--;
		if (target._keeperMode)
			this->takeDamage(this->_attackDamage);
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " is too tired to attack, there's no energy left.\n");
	}
	else if (target.getHitPoints() <= 0) {
		println(WHT << "       " << target._name << " is not moving anymore. It's best to not touch it, " << this->_name << ".\n");
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is unresponsive. Cannot attack.\n");
	}
}

void	ScavTrap::guardGate(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " activates gate keeper mode.\n       Be careful when attacking.");
		this->_energyPoints--;
		this->_keeperMode = true;
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " is so weak now... He can't guard the gate anymore.\n");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " perished trying to protect the vault's entrance.\n");
	}
}

bool	ScavTrap::getKeeperMode(void) {
	return (this->_keeperMode);
}

void	ScavTrap::setKeeperMode(bool mode) {
	this->_keeperMode = mode;
}
