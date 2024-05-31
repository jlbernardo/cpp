/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:45:49 by julberna          #+#    #+#             */
/*   Updated: 2024/05/30 21:20:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string	_name;

public:
			DiamondTrap(void);
			~DiamondTrap(void);
			DiamondTrap(DiamondTrap &copy);
			DiamondTrap(std::string name);
	void	whoAmI(void);
	void	attack(DiamondTrap &target);
	void	attack(const std::string &target);
	std::string	getDiamondName(void);
};

#endif
