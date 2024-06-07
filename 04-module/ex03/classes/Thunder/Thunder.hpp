/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:49 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 21:27:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef THUNDER_HPP
# define THUNDER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Thunder : public AMateria {

public:
				Thunder(void);
				Thunder(Thunder const &other);
	virtual 	~Thunder(void);

	Thunder			&operator=(Thunder const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
};

#endif
