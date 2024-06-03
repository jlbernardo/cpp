/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:45:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 20:14:06 by julberna         ###   ########.fr       */
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

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	println(GRN << "     DiamondTrap copy constructor called for " << copy._name << ".\n");
	*this = copy;
}

void	DiamondTrap::operator=(const DiamondTrap &copy) {
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

DiamondTrap::~DiamondTrap(void) {
	println(RED << "\n     DiamondTrap destructor called for " << this->_name << ".");
}

void	DiamondTrap::whoAmI(void) {
	println(WHT << "       Ì̷͙ ̴̨̇ā̵̟" << RED << "m̵͔̈́ " << WHT << this->_name
				<< " ̷̫̅a̸͉͛n̴̟̕d̴͙̋ ̷͔̈́" << RED << " ̸͔̎m̶̘̄y ̴͕̕C̶̲̊" << WHT
				<< "l̸͖͝ḁ̶̉p" << RED << "Tr̷̛͔ä̴̳́p̸͓̃ ̷̖͌n̵̡̕a̶̮̋" << WHT << "m̴͇̅e" << RED
				<< " ̸̩̒i̶͓̐s̴͍͊ ̵͖̔" << WHT << this->ClapTrap::_name << ".");
				
	println(RED << "              A̶͖̐ ̵̤̎R̷̰͊ ̷͇̆Ĕ̷̲" << WHT << " ̵̛̠ ̷̙́ ̷͙͠Ÿ̴̧" << RED
				<< " ̴̘͊O̵̟͘ ̸͉͆U̴̱̾ ̸̞̉ ̵͕͑ ̸̝̇M̷̪̃ ̷̤̈́Y̶̰̓ ̵̠̑ ̴͋ͅ ̵̼̀" << WHT << "M̶̛̤ ̸̮̋O̸̹͂ ̴͈͛" << RED
				<< "M̴̹͋ ̸̾ͅM̷̫͝ ̵̭̓Ȳ̶̧ ̷͉̓ ̸̮͝?̴͉̾ ̴̝̊" << WHT << "?̵̘̈́" << RED << "");
}

std::string	DiamondTrap::getDiamondName(void) {
	return this->_name;
}
