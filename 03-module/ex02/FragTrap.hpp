/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:13:21 by julberna          #+#    #+#             */
/*   Updated: 2024/06/02 22:07:46 by julberna         ###   ########.fr       */
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
	void	operator=(const FragTrap &copy);
	void	highFivesGuys(void);
	void	setEnergyCorrection(unsigned int bonus);

};

#endif
