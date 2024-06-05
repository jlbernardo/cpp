/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:23:32 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 17:30:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

public:
				Cat(void);
				~Cat(void);
				Cat(const Cat &copy);
	void		operator=(const Cat &copy);

	void		makeSound(void) const;

};

#endif
