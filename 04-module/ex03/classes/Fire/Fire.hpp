/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 21:21:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIRE_HPP
# define FIRE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Fire : public AMateria {

public:
				Fire(void);
				Fire(Fire const &other);
	virtual 	~Fire(void);

	Fire			&operator=(Fire const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
};

#endif
