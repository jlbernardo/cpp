/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:08:37 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 14:18:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include	<iostream>
# include	<iomanip>
# include	"general.hpp"

/**
 * #### ClapTrap class
 * Has a name, hit points, attack damage and energy points.
 */
class ClapTrap {

private:
	std::string		_name;			// Name of the robot
	unsigned int	_hitPoints;		// Health of the robot
	unsigned int	_attackDamage;	// How much damage the robot can deal
	unsigned int	_energyPoints;	// How many times the robot can act

public:
					/**
					 * @brief Constructs a new Clap Trap object.
					 */
					ClapTrap(void);

					/**
					 * @brief This basically kills the robot...
					 */
					~ClapTrap(void);

					/**
					 * @brief Constructs a new Clap Trap object with a given name.
					 * @param name it's how we call it.
					 */
					ClapTrap(std::string name);

					/**
					 * @brief Constructs a new Clap Trap object, identical to the copy.
					 * @param copy the robot from which to copy from.
					 */
					ClapTrap(const ClapTrap &copy);

					/**
					 * @brief Copies all information from the copy to the current object.
					 * @param copy the robot from which to copy from.
					 */
	void			operator=(const ClapTrap &copy);

					/**
					 * @brief Upgrades the robot, increasing its damage.
					 */
	void			upgrade(void);

					/**
					 * @brief Attacks the target, dealing damage and reducing its hit points.
					 * @param target the enemy.
					 */
	void			attack(ClapTrap &target);

					/**
					 * @brief Deals damage to the robot, reducing its hit points.
					 * @param amount the total damage to suffer.
					 */
	void			takeDamage(unsigned int amount);

					/**
					 * @brief Heals the robot, increasing its hit points.
					 * @param amount the total health to recover.
					 */
	void			beRepaired(unsigned int amount);

					/**
					 * @brief Attacks the given target name, only for display purposes.
					 * @param target the enemy's name.
					 */
	void			attack(const std::string &target);

					/**
					 * @brief Gets the name of the robot.
					 * @return std::string - the robot's name.
					 */
	std::string		getName(void) const;

					/**
					 * @brief Gets the hit points of the robot.
					 * @return unsigned int - the robot's health.
					 */
	unsigned int	getHitPoints(void) const;

					/**
					 * @brief Gets the energy points of the robot.
					 * @return unsigned int - the robot's energy.
					 */
	unsigned int	getEnergyPoints(void) const;

					/**
					 * @brief Gets the attack damage of the robot.
					 * @return unsigned int - the robot's damage.
					 */
	unsigned int	getAttackDamage(void) const;
};

#endif
