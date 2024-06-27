/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:46:54 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 17:16:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "data.hpp"

/**
 * #### Serializer class
 *
 * A class capable of transformind a Data structure into a uintptr_t and vice versa.
 */
class Serializer {
private:
						/**
						 * @brief Constructs a new Serializer object.
						 */
						Serializer(void);

						/**
						 * @brief Destroys the Serializer object.
						 */
						~Serializer(void);

						/**
						 * @brief Copy constructor.
						 * @param copy The object to copy from.
						 */
						Serializer(const Serializer &copy);

						/**
						 * @brief Assignment operator.
						 * @param rhs The object to copy from.
						 * @return Serializer& - A reference to the object.
						 */
	Serializer			&operator=(const Serializer &rhs);

public:
						/**
						 * @brief Serialize a Data structure into a uintptr_t.
						 * @param ptr The pointer to the Data structure.
						 * @return uintptr_t - The serialized Data structure.
						 */
	static uintptr_t	serialize(Data *ptr);

						/**
						 * @brief Deserialize a uintptr_t into a Data structure.
						 * @param raw The serialized Data structure.
						 * @return Data* - The deserialized Data structure.
						 */
	static Data			*deserialize(uintptr_t raw);
};

#endif
