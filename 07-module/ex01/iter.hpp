/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:05:52 by julberna          #+#    #+#             */
/*   Updated: 2024/07/03 00:39:22 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

# include "general.hpp"

template<typename T>
void iter(T *array, int len, void (*f)(T const &)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void iter(T *array, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void print(T const &i) {
	println(i);
}

template<typename T>
void plusFive(T &i) {
	i = i + 5;
	println(static_cast<T>(i));
}

#endif
