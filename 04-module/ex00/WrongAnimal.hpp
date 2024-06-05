/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:24:31 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 20:12:05 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "general.hpp"

class WrongAnimal {

protected:
	std::string	_type;

public:
						WrongAnimal(void);
	virtual				~WrongAnimal(void);
						WrongAnimal(std::string type);
						WrongAnimal(const WrongAnimal &copy);
	void				operator=(const WrongAnimal &copy);

	void				makeSound(void) const;
	const std::string	&getType(void) const;
};

#endif
