/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:20:04 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 22:16:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

# include "general.hpp"

/**
 * #### Base class
 */
class Base {
public:
				/**
				 * @brief Virtual destructor.
				 */
	virtual		~Base(void);
};

#endif
