/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:45:41 by julberna          #+#    #+#             */
/*   Updated: 2024/05/30 21:36:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unknown_clap_name"), _name("Unknown") {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	println(GRN << "     DiamondTrap constructor called for " << this->_name << ".\n");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	println(GRN << "     DiamondTrap constructor called for " << this->_name << ".\n");
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) {
	println(GRN << "     DiamondTrap copy constructor called for " << copy._name << ".\n");
	*this = copy;
}

DiamondTrap::~DiamondTrap(void) {
	println(this->_hitPoints);
	println(RED << "\n     DiamondTrap destructor called for " << this->_name << ".");
}

void	DiamondTrap::whoAmI(void) {
	println(WHT << "       I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << ".");
}

void	DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::attack(DiamondTrap &target) {
	this->ScavTrap::attack(target._name);
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && target.getHitPoints() > 0) {
		target.takeDamage(this->_attackDamage);
		if (target._keeperMode)
			this->takeDamage(this->_attackDamage);
	}
	else if (target.getHitPoints() <= 0) {
		this->_energyPoints--;
	}
}

std::string	DiamondTrap::getDiamondName(void) {
	return this->_name;
}
