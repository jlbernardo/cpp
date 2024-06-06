/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:34:46 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 13:48:23 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "general.hpp"

class Brain {

protected:
	std::string	_ideas[100];

public:

				Brain(void);
				~Brain(void);
				Brain(const Brain &copy);
	void		operator=(const Brain &copy);

	void		print(void) const;
	void		think(std::string idea);
};

#endif
