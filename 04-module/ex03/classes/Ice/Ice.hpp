/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 21:05:16 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

public:
				Ice(void);
				Ice(Ice const &other);
	virtual 	~Ice(void);

	Ice			&operator=(Ice const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
};

#endif
