/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 18:02:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "general.hpp"

class Animal {

protected:
	std::string	_type;

public:
						Animal(void);
	virtual				~Animal(void);
						Animal(std::string type);
						Animal(const Animal &copy);
	void				operator=(const Animal &copy);

	virtual void		makeSound(void) const;
	const std::string	&getType(void) const;
};

#endif
