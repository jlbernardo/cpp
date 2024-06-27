/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:46:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 16:12:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::~Serializer(void) {
}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
}

Serializer	&Serializer::operator=(const Serializer &rhs) {
	(void)rhs;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
