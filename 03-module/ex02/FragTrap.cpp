/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:19 by julberna          #+#    #+#             */
/*   Updated: 2024/05/27 17:20:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "     FragTrap constructor called for " << this->_name << ".");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	println(CYN << "     FragTrap constructor called for " << this->_name << ".");
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy) {
	println(CYN << "     FragTrap copy constructor called for " << this->_name << ".");
}

FragTrap::~FragTrap(void) {
	println(PRP << "     FragTrap destructor called for " << this->_name << ".");
}

void	FragTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println(WHT << "       " << this->_name << " assaults " << target << ", attack deals " << this->_attackDamage << " points of damage.");
		this->_energyPoints--;
	}
	if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " got distracted by a blinking light in its chest... I think the battery is dead.");
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       It's over for you, " << this->_name << ". You can get revenge some other time.\n");
	}
}

void	FragTrap::attack(FragTrap &target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && target.getHitPoints() > 0) {
		println(WHT << "       " << this->_name << " assaults " << target._name << ", attack deals " << this->_attackDamage << " points of damage.");
		target.takeDamage(this->_attackDamage);
		this->_energyPoints--;
	}
	else if (this->_energyPoints <= 0) {
		println(WHT << "       " << this->_name << " got distracted by a blinking light in its chest... I think the battery is dead.\n");
	}
	else if (target.getHitPoints() <= 0) {
		println(WHT << "       Don't be mean, " << this->_name << "! " << target._name << " can barely breathe. Leave it alone.\n");
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0) {
		println(WHT << "       It's over for you, " << this->_name << ". You can get revenge some other time.\n");
	}
}

void	FragTrap::highFivesGuys(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		println("\033c");
		println(WHT << "\n       Huh?! Looks like " << this->_name << " wants a high five. What do you say?\n\n\n");
		this->_energyPoints--;
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
