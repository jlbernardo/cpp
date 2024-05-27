/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:21 by julberna          #+#    #+#             */
/*   Updated: 2024/05/27 17:16:57 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
			FragTrap(void);
			~FragTrap(void);
			FragTrap(FragTrap &copy);
			FragTrap(std::string name);
	void	attack(FragTrap &target);
	void	attack(const std::string &target);
	void	highFivesGuys(void);
	void	setEnergyCorrection(unsigned int bonus);

};

#endif
