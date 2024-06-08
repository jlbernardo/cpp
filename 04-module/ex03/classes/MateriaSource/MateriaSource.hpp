/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:51:44 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 21:36:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "ICharacter.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria		*_materia[4];

public:
					MateriaSource(void);
					MateriaSource(MateriaSource const &other);
					~MateriaSource(void);

	MateriaSource	&operator=(MateriaSource const &other);

	void			learnMateria(AMateria *m);
	void			forgetMateria(int idx);
	AMateria		*createMateria(std::string const &type);
};

#endif
