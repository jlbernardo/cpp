/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:45:52 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 17:00:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/**
 * #### ScavTrap class, derived from ClapTrap
 * Has everything that ClapTrap has, plus a new method `guardGate()`.
 */
class ScavTrap : virtual public ClapTrap {

private:
	bool	_keeperMode;			// Determines if the robot is on keeper mode

public:
			/**
			 * @brief Constructs a new Scav Trap object.
			 */
			ScavTrap(void);

			/**
			 * @brief This basically kills the robot...
			 */
			~ScavTrap(void);

			/**
			 * @brief Constructs a new Scav Trap object with a given name.
			 * @param name it's how we call it.
			 */
			ScavTrap(std::string name);

			/**
			 * @brief Constructs a new Scav Trap object, identical to the copy.
			 * @param copy the robot from which to copy from.
			 */
			ScavTrap(const ScavTrap &copy);

			/**
			 * @brief Copies all information from the copy to the current object.
			 * @param copy the robot from which to copy from.
			 */
	void	operator=(const ScavTrap &copy);

			/**
			 * @brief Attacks a target robot with a different message, still dealing damage and reducing enemy's hit points.
			 * @param target the robot to attack.
			 */
	void	attack(ScavTrap &target);

			/**
			 * @brief Attacks the given target's name, only for display purposes.
			 * @param target the enemy's name.
			 */
	void	attack(const std::string &target);

			/**
			 * @brief Activates the gate keeper mode, where the attacker will also take damage if it attacks the robot.
			 */
	void	guardGate(void);

			/**
			 * @brief Gets the gate keeping status.
			 * @return true if the robot is on keeper mode, false otherwise.
			 */
	bool	getKeeperMode(void);

			/**
			 * @brief Sets the gate keeping mode.
			 * @param mode true for on, false for off.
			 */
	void	setKeeperMode(bool mode);
};

#endif
