/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:22 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 20:17:12 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Cure : public AMateria {

public:
				Cure(void);
				Cure(Cure const &other);
	virtual 	~Cure(void);

	Cure		&operator=(Cure const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
	void		use(Character &target);
};

#endif
