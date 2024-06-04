/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:19 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 23:27:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "                    FragTrap constructor called for " << this->_name << ".");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "                    FragTrap constructor called for " << this->_name << ".");
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	println(CYN << "                    FragTrap copy constructor called for " << this->_name << ".");
	*this = copy;
}

void	FragTrap::operator=(const FragTrap &copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

FragTrap::~FragTrap(void) {
	println(PRP << "                    FragTrap destructor called for " << this->_name << ".");
}

void	FragTrap::highFivesGuys(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		println("\033c");
		println(WHT << "\n                      Huh?! Looks like " << this->_name << " wants a high five. What do you say?");
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "                      " << this->_name << " cannot raise its hand, despite all efforts.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "                      " << this->_name << " just wanted to make some friends... Look at the poor thing now.");
	}
}

void	FragTrap::setEnergyCorrection(unsigned int bonus) {
	this->_energyPoints += bonus;
}
