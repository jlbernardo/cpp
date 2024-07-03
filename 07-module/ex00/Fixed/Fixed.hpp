/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:25:32 by julberna          #+#    #+#             */
/*   Updated: 2024/05/20 22:46:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include	<cmath>
# include	<iomanip>
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
	void	operator=(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is greater than the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is greater than the operand, `false` if not.
			 */
	bool	operator>(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is less than the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is less than the operand, `false` if not.
			 */
	bool	operator<(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is greater than or equal to the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is greater or equal than the operand, `false` if not.
			 */
	bool	operator>=(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is less than or equal to the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is less or equal than the operand, `false` if not.
			 */
	bool	operator<=(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is equal to the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is equal to the operand, `false` if not.
			 */
	bool	operator==(const Fixed &operand);

			/**
			 * @brief Compares if a Fixed object is not equal to the other.
			 *
			 * @param operand the object to compare with.
			 * @return `true` if the object is not equal to the operand, `false` if not.
			 */
	bool	operator!=(const Fixed &operand);

			/**
			 * @brief Adds two Fixed objects.
			 *
			 * @param operand the object to add.
			 * @return Fixed – the result of the addition.
			 */
	Fixed	operator+(const Fixed &operand);

			/**
			 * @brief Subtracts two Fixed objects.
			 *
			 * @param operand the object to subtract.
			 * @return Fixed – the result of the subtraction.
			 */
	Fixed	operator-(const Fixed &operand);

			/**
			 * @brief Multiplies two Fixed objects.
			 *
			 * @param operand the object to multiply.
			 * @return Fixed – the result of the multiplication.
			 */
	Fixed	operator*(const Fixed &operand);

			/**
			 * @brief Divides two Fixed objects.
			 *
			 * @param operand the object to divide.
			 * @return Fixed – the result of the division.
			 */
	Fixed	operator/(const Fixed &operand);

			/**
			 * @brief Pre increments the Fixed object.
			 * @return Fixed – a reference to the incremented object.
			 */
	Fixed	&operator++(void);

			/**
			 * @brief Post increments the Fixed object.
			 * @return Fixed – a copy of the object before incrementation.
			 */
	Fixed	operator++(int);

			/**
			 * @brief Pre decrements the Fixed object.
			 * @return Fixed – a reference to the decremented object.
			 */
	Fixed	&operator--(void);

			/**
			 * @brief Post decrements the Fixed object.
			 * @return Fixed – a copy of the object before decrementation.
			 */
	Fixed	operator--(int);

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

			/**
			 * @brief Returns the minimum of two Fixed objects.
			 * @param one the first object.
			 * @param two the second object.
			 * @return Fixed - a reference to the smaller object.
			 */
	static Fixed	&min(Fixed &one, Fixed &two);

			/**
			 * @brief Returns the minimum of two constant Fixed objects.
			 * @param one the first object.
			 * @param two the second object.
			 * @return Fixed - a reference to the smaller object.
			 */
	static const Fixed	&min(const Fixed &one, const Fixed &two);

			/**
			 * @brief Returns the maximum of two Fixed objects.
			 * @param one the first object.
			 * @param two the second object.
			 * @return Fixed - a reference to the greater object.
			 */
	static Fixed	&max(Fixed &one, Fixed &two);

			/**
			 * @brief Returns the maximum of two constant Fixed objects.
			 * @param one the first object.
			 * @param two the second object.
			 * @return Fixed - a reference to the greater object.
			 */
	static const Fixed	&max(const Fixed &one, const Fixed &two);

};

/**
 * @brief Overloaded << operator to print the Fixed class object.
 * @param os the output stream.
 * @param obj the Fixed class object to be printed.
 * @return std::ostream& - the output stream.
 */
std::ostream &operator<<(std::ostream &os, Fixed const &obj);

/**
 * @brief Runs the tests included in the pdf.
 */
void	pdf_tests(void);

/**
 * @brief Runs comparison tests.
 */
void	comparison_tests(void);

/**
 * @brief Runs arithmetic tests.
 */
void	arithmetic_tests(void);

# define TRUE	"\033[32mtrue\033[0m"
# define FALSE	"\033[31mfalse\033[0m"
# define ONE	RED << "a" << DFL << " + 2"
# define TWO	GRN << "b" << DFL << " - 2"
# define THREE	CYN << "c" << DFL << " * 2"
# define FOUR	YLW << "d" << DFL << " / 2"
# define FIVE	RED << "a" << DFL " + " << GRN << "b" << DFL << " / " << CYN << "c" << DFL << " - " << YLW << "d" << DFL
# define SIX	GRN << "b" << DFL << " * " << YLW << "d" << DFL << " + " << YLW << "d" << DFL
# define SEVEN	YLW << "d" << DFL << " / " << RED << "a" << DFL << " - " << CYN << "c" << DFL
# define EIGHT	YLW << "d" << DFL << " - " << CYN << "c" << DFL << " * (" << CYN << "c" << DFL << " + " << RED << "a" << DFL << ")"
# define NINE	YLW << "d" << DFL << " - " << CYN << "c" << DFL << " - " << CYN << "c" << DFL
# define TEN	RED << "a" << DFL << " / (" << RED << "a" << DFL << " + " << GRN << "b" << DFL << ") * " << CYN << "c" << DFL
# define ELEVEN	RED << "a" << DFL << " + " << GRN << "b" << DFL << " + " << CYN << "c" << DFL << " + " << YLW << "d" << DFL
# define TWELVE	GRN << "b" << DFL << " + " << GRN << "b" << DFL << " - " << RED << "a" << DFL << " + " << RED << "a" << DFL

#endif
