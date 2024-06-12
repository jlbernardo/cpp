/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:36:47 by julberna          #+#    #+#             */
/*   Updated: 2024/06/12 14:05:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "general.hpp"

class ICharacter;
class Character;

class AMateria
{
protected:
	std::string			_type;	//The materia type
	std::string			_gem;	//The materia gem

public:
						AMateria(void);
	virtual				~AMateria(void);
						AMateria(std::string const &type);
	AMateria			&operator=(const AMateria &copy);

	std::string const	&getType() const;
	std::string const	&getGem() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter &target);
	virtual void		use(Character &target);
};

#endif
