/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 20:16:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIRE_HPP
# define FIRE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Fire : public AMateria {

public:
				Fire(void);
				Fire(Fire const &other);
	virtual 	~Fire(void);

	Fire			&operator=(Fire const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
	void		use(Character &target);
};

#endif
