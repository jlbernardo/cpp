/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:08:37 by julberna          #+#    #+#             */
/*   Updated: 2024/05/24 18:52:30 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include	<iostream>
# include	<iomanip>
# include	"general.hpp"

class ClapTrap {

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_attackDamage;
	unsigned int	_energyPoints;

public:
				ClapTrap(void);
				~ClapTrap(void);
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap &copy);
	void		operator=(const ClapTrap &copy);

	void		upgrade(void);
	void		attack(ClapTrap &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		attack(const std::string &target);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
};

#endif
