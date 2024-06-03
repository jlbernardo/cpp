/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:45:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:56:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _keeperMode(false) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	println(CYN << "     ScavTrap constructor called for " << this->_name << ".\n");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _keeperMode(false) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	println(CYN << "     ScavTrap constructor called for " << this->_name << ".\n");
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _keeperMode(false) {
	println(CYN << "     ScavTrap copy constructor called for " << this->_name << ".\n");
	*this = copy;
}

ScavTrap::~ScavTrap(void) {
	println(PRP << "\n     ScavTrap destructor called for " << this->_name << ".");
}

void	ScavTrap::operator=(const ScavTrap &copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " strikes "
					<< target << ", " << this->_attackDamage << " points of damage dealt.");
		this->_energyPoints--;
	}
	if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " is too tired to attack, there's no energy left.\n");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       " << this->_name << " is unresponsive. Cannot attack.\n");
	}
}

void	ScavTrap::attack(ScavTrap &target) {
	if (target.getHitPoints() > 0) {
		this->attack(target._name);
		if (this->_energyPoints > 0 && this->_hitPoints > 0) {
			target.takeDamage(this->_attackDamage);
			if (target._keeperMode)
				this->takeDamage(this->_attackDamage);
		}
	}
	else {
		println(WHT << "       " << target._name << " is not moving anymore. It's best to not touch it, "
					<< this->_name << ".\n");
		this->_energyPoints--;
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
