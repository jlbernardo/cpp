/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:47:22 by julberna          #+#    #+#             */
/*   Updated: 2024/07/07 17:22:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include "general.hpp"

template <typename T>
typename T::iterator	easyfind(T container, int value) {

	typename T::iterator match;

	match = std::find(container.begin(), container.end(), value);

	if (match == container.end())
		throw std::runtime_error("No matches found.");

	return (match);
}

#endif
