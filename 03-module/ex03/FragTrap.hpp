/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:21 by julberna          #+#    #+#             */
/*   Updated: 2024/06/03 16:59:55 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

/**
 * #### FragTrap class
 * Has everything that ClapTrap has, plus a new method `highFivesGuys()`.
 */
class FragTrap : virtual public ClapTrap {

public:
			/**
			 * @brief Constructs a new Frag Trap object.
			 */
			FragTrap(void);

			/**
			 * @brief This basically kills the robot...
			 */
			~FragTrap(void);

			/**
			 * @brief Constructs a new Frag Trap object with a given name.
			 * @param name it's how we call it.
			 */
			FragTrap(std::string name);

			/**
			 * @brief Constructs a new Frag Trap object, identical to the copy.
			 * @param copy the robot from which to copy from.
			 */
			FragTrap(const FragTrap &copy);

			/**
			 * @brief Copies all information from the copy to the current object.
			 * @param copy the robot from which to copy from.
			 */
	void	operator=(const FragTrap &copy);

			/**
			 * @brief Asks for a high five. It just wants to make friends.
			 */
	void	highFivesGuys(void);

			/**
			 * @brief Adds energy points back to the robot after high fiving routine.
			 * @param bonus the amount of energy to replenish.
			 */
	void	setEnergyCorrection(unsigned int bonus);
};

#endif
