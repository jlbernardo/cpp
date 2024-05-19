/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:25:32 by julberna          #+#    #+#             */
/*   Updated: 2024/05/19 15:39:39 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include	<cmath>
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
			Fixed(Fixed const &copy);

			/**
			 * @brief Constructs a new Fixed object with a given int value.
			 * @param value the value to be set.
			 */
			Fixed(int const value);

			/**
			 * @brief Constructs a new Fixed object with a given float value.
			 * @param value the value to be set.
			 */
			Fixed(float const value);

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

			/**
			 * @brief Converts the Fixed class object to a float.
			 * @return float - the converted value.
			 */
	float	toFloat(void) const;

			/**
			 * @brief Converts the Fixed class object to an int.
			 * @return int - the converted value.
			 */
	int		toInt(void) const;

};

/**
 * @brief Overloaded << operator to print the Fixed class object.
 * @param os the output stream.
 * @param obj the Fixed class object to be printed.
 * @return std::ostream& - the output stream.
 */
std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif
