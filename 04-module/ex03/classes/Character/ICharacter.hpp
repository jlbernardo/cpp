/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:26:43 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 21:06:22 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "general.hpp"

# define	MAX_MATERIA	4
# define	TOTAL_HP	100

#include "AMateria.hpp"

class ICharacter
{
public:
	virtual 					~ICharacter() {}
	virtual void				unequip(int idx) = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual std::string const	&getName(void) const = 0;
	virtual unsigned int const	&getHealth(void) const = 0;
	virtual AMateria			*getMateria(int idx) const = 0;
	virtual std::string const	getMateriaGem(int idx) const = 0;
	virtual std::string const	getMateriaType(int idx) const = 0;
	virtual void				modHealth(int amount) = 0;
	virtual void				setHealth(unsigned int amount) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

#endif
