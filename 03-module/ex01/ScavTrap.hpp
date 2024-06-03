/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:45:52 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 15:55:35 by julberna         ###   ########.fr       */
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
class ScavTrap : public ClapTrap {

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
			ScavTrap(const ScavTrap &copy);
	void	operator=(const ScavTrap &copy);
	void	attack(ScavTrap &target);
	void	attack(const std::string &target);
	void	guardGate(void);
	bool	getKeeperMode(void);
	void	setKeeperMode(bool mode);
};

#endif
