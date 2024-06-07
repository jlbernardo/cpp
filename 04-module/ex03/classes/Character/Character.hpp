/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:37:38 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 00:25:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "MateriaSource.hpp"

class Character : public ICharacter
{
private:
	std::string			_name;
	unsigned int		_health;
	AMateria			*_materia[MAX_MATERIA];

public:
						Character(void);
						Character(std::string const &name);
						Character(Character const &other);
						~Character(void);

	Character			&operator=(Character const &other);

	void				unequip(int idx);
	void				equip(AMateria *m);
	void				use(int idx, ICharacter &target);

	std::string const	&getName(void) const;
	unsigned int const	&getHealth(void) const;
	std::string const	getMateriaGem(int idx) const;
	std::string const	getMateriaType(int idx) const;

	void				modHealth(int amount);
};

#endif
