/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:45:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 20:04:18 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/**
 * #### DiamondTrap class, lost child of Scav and Trap. It is... Weird.
 * Has everything from preivous classes and keeps introducing itself.
 */
class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string	_name;				// The name of the robot

public:
				/**
				 * @brief Constructs a new Diamond Trap object.
				 */
				DiamondTrap(void);

				/**
				 * @brief This basically kills the robot...
				 */
				~DiamondTrap(void);

				/**
				 * @brief Constructs a new Diamond Trap object with a given name.
				 * @param name it's how we call it.
				 */
				DiamondTrap(std::string name);

				/**
				 * @brief Constructs a new Diamond Trap object, identical to the copy.
				 * @param copy the robot from which to copy from.
				 */
				DiamondTrap(DiamondTrap &copy);

				/**
				 * @brief Copies all information from the copy to the current object.
				 * @param copy the robot from which to copy from.
				 */
	void		operator=(const DiamondTrap &copy);

				/**
				 * @brief Robot says its name and its ClapTrap name.
				 */
	void		whoAmI(void);

				/**
				 * @brief Gets the diamond name of the robot.
				 * @return std::string - robot's diamond name.
				 */
	std::string	getDiamondName(void);
};

#endif
