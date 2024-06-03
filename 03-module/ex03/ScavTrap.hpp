/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:45:52 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 21:39:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

private:
	bool	_keeperMode;

public:
			ScavTrap(void);
			~ScavTrap(void);
			ScavTrap(ScavTrap &copy);
			ScavTrap(std::string name);
	void	operator=(const ScavTrap &copy);
	void	attack(ScavTrap &target);
	void	attack(const std::string &target);
	void	guardGate(void);
	bool	getKeeperMode(void);
	void	setKeeperMode(bool mode);
};

#endif
