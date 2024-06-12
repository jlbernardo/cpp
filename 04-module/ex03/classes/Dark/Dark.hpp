/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dark.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:13:22 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 20:17:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DARK_HPP
# define DARK_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Dark : public AMateria {

public:
				Dark(void);
				Dark(Dark const &other);
	virtual 	~Dark(void);

	Dark		&operator=(Dark const &other);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);
	void		use(Character &target);
};

#endif
