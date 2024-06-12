/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:26:43 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 20:37:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "general.hpp"

# define	MAX_MATERIA	4
# define	PHASE1_HP	100
# define	PHASE2_HP	150
# define	PHASE3_HP	200

#include "AMateria.hpp"

class ICharacter
{
public:
	virtual 					~ICharacter() {}
	virtual void				unequip(int idx) = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual std::string const	&getName(void) const = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

#endif
