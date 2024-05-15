/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:25:32 by julberna          #+#    #+#             */
/*   Updated: 2024/05/15 16:37:24 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include	<iostream>
# include	"general.hpp"

/**
 * #### Fixed point class
 * Has an integer value and a fixed number of fractional bits.
 */
class Fixed {

private:
	int					_value;		// value of the fixed point number
	static const int	_bits = 8;	// number of fractional bits

public:
			/**
			 * @brief Constructs a new Fixed object.
			 */
			Fixed(void);

			/**
			 * @brief Destroys the Fixed object.
			 */
			~Fixed(void);

			/**
			 * @brief Copy constructor of Fixed class object.
			 * @param copy the object from which to copy from.
			 */
			Fixed(Fixed &copy);

			/**
			 * @brief Overloaded assignment operator. Copies the value from one object to the other.
			 * @param copy the object from which to copy from.
			 */
	void	operator=(const Fixed &copy);

			/**
			 * @brief Sets the the raw bits of the Fixed class object.
			 * @param raw the raw value to be set.
			 */
	void	setRawBits(int const raw);

			/**
			 * @brief Gets the raw bits of the Fixed class object.
			 * @return int - the raw value.
			 */
	int		getRawBits(void) const;

};

#endif
