/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:19 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 22:07:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "     FragTrap constructor called for " << this->_name << ".\n");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "     FragTrap constructor called for " << this->_name << ".\n");
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy) {
	println(CYN << "     FragTrap copy constructor called for " << this->_name << ".\n");
	*this = copy;
}

void	FragTrap::operator=(const FragTrap &copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

FragTrap::~FragTrap(void) {
	println(PRP << "\n     FragTrap destructor called for " << this->_name << ".");
}

void	FragTrap::highFivesGuys(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		println("\033c");
		println(WHT << "\n       Huh?! Looks like " << this->_name << " wants a high five. What do you say?\n\n\n");
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "\n       " << this->_name << " cannot raise its hand, despite all efforts.\n\n\n");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "\n       " << this->_name << " just wanted to make some friends... Look at the poor thing now.\n\n\n");
	}
}

void	FragTrap::setEnergyCorrection(unsigned int bonus) {
	this->_energyPoints += bonus;
}
