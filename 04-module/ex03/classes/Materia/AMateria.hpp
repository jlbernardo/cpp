/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:36:47 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 23:18:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "general.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string			_type;	//The materia type
	std::string			_gem;	//The materia gem

public:
						AMateria(void);
	virtual				~AMateria(void);
						AMateria(std::string const &type);

	std::string const	&getType() const; //Returns the materia type
	std::string const	&getGem() const; //Returns the materia gem
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif
