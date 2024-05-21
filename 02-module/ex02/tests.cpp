/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:58:57 by julberna          #+#    #+#             */
/*   Updated: 2024/05/20 22:49:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	pdf_tests(void) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	println("\n  First, let's run the tests from the PDF:\n");
	println(WHT << "        Fixed a;\n        Fixed const b(Fixed(5.05f) * Fixed(2));\n");
	println("      ╭───────────────────────────╮")
	println("      │          a = " << a << "            │");
	println("      │        ++a = " << ++a << "   │");
	println("      │          a = " << a << "   │");
	println("      │        a++ = " << a++ << "   │");
	println("      │          a = " << a << "    │");
	println("      │          b = " << b << "      │");
	println("      │  max(a, b) = " << Fixed::max( a, b ) << "      │");
	println("      │  min(a, b) = " << Fixed::min( a, b ) << "    │");
	println("      ╰───────────────────────────╯")
	println("            ᵖʳᵉˢˢ ᵉⁿᵗᵉʳ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");

	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);
}

void	comparison_tests(void) {

	Fixed a(42.43f);
	Fixed b(42.42f);

	println("\033c");
	println("  Now we can run some other tests. Let's try some comparisons:\n")
	println(WHT << "        Fixed a(42.4"<< GRN << "3" << WHT << ");");
	println(WHT << "        Fixed b(42.4"<< RED << "2" << WHT << ");\n");
	println("      ╭───────────────────────────╮")
	println("      │        a < b = " << ((a < b) ? TRUE : FALSE) << "      │");
	println("      │        a > b = " << ((a > b) ? TRUE : FALSE) << "       │");
	println("      │       a == b = " << ((a == b) ? TRUE : FALSE) << "      │");
	println("      │       a != b = " << ((a != b) ? TRUE : FALSE) << "       │");
	println("      │       a >= b = " << ((a >= b) ? TRUE : FALSE) << "       │");
	println("      │       a <= b = " << ((a <= b) ? TRUE : FALSE) << "      │");
	println("      │                           │")
	println("      │           " << WHT << " b + 1 " << DFL << "         │"); b = b + 1;
	println("      │                           │")
	println("      │        a < b = " << ((a < b) ? TRUE : FALSE) << "       │");
	println("      │        a > b = " << ((a > b) ? TRUE : FALSE) << "      │");
	println("      │       a == b = " << ((a == b) ? TRUE : FALSE) << "      │");
	println("      │       a != b = " << ((a != b) ? TRUE : FALSE) << "       │");
	println("      │       a >= b = " << ((a >= b) ? TRUE : FALSE) << "      │");
	println("      │       a <= b = " << ((a <= b) ? TRUE : FALSE) << "       │");
	println("      ╰───────────────────────────╯")
	println("            ᵖʳᵉˢˢ ᵉⁿᵗᵉʳ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");

	std::string	input("not empty");
	while (!input.empty())
		getline(std::cin, input);

}

void	arithmetic_tests(void) {

	Fixed a(66.66f);
	Fixed b(99.99f);
	Fixed c(11.11f);
	Fixed d(55.55f);
	float aa(66.66f);
	float bb(99.99f);
	float cc(11.11f);
	float dd(55.55f);

	println("\033c");
	println("  Time for arithmetics:\n")
	println(WHT << "        Fixed a("<< RED << "66.66" << WHT << ");");
	println(WHT << "        Fixed b("<< GRN << "99.99" << WHT << ");");
	println(WHT << "        Fixed c("<< CYN << "11.11" << WHT << ");");
	println(WHT << "        Fixed d("<< YLW << "55.55" << WHT << ");\n");
	println("      ╭───────────────────────────────────╮")
	println("      │              " << ONE << " = " << a + 2 << "      │");
	println("      │              " << TWO << " = " << b - 2 << "      │");
	println("      │              " << THREE << " = " << c * 2 << "      │");
	println("      │              " << FOUR << " = " << d / 2 << "      │");
	println("      │      " << FIVE << " = " << a + b / c - d << "      │");
	println("      │          " << SIX << " = " << b * d + d	 << "      │");
	println("      │          " << SEVEN << " = " << d / a - c << "     │");
	println("      │    " << EIGHT << " = " << d - c * (c + a) << "     │");
	println("      │          " << NINE << " = " << d - c - c << "       │");
	println("      │    " << TEN << " = " << a / (a + b) * c << "      │");
	println("      │      " << ELEVEN << " = " << a + b + c + d << "      │");
	println("      │      " << TWELVE << " = " << b + b - a + a << "      │");
	println("      ╰───────────────────────────────────╯")
	println("");
	println("\n  Same operations using floats:")
	println("      ╭───────────────────────────────────╮")
	println("      │              " << ONE << " = " << aa + 2 << "        │");
	println("      │              " << TWO << " = " << bb - 2 << "        │");
	println("      │              " << THREE << " = " << cc * 2 << "        │");
	println("      │              " << FOUR << " = " << dd / 2 << "       │");
	println("      │      " << FIVE << " = " << aa + bb / cc - dd << "        │");
	println("      │          " << SIX << " = " << bb * dd + dd	 << "      │");
	println("      │          " << SEVEN << " = " << dd / aa - cc << "     │");
	println("      │    " << EIGHT << " = " << dd - cc * (cc + aa) << "     │");
	println("      │          " << NINE << " = " << dd - cc - cc << "        │");
	println("      │    " << TEN << " = " << aa / (aa + bb) * cc << "        │");
	println("      │      " << ELEVEN << " = " << aa + bb + cc + dd << "       │");
	println("      │      " << TWELVE << " = " << bb + bb - aa + aa << "       │");
	println("      ╰───────────────────────────────────╯\n")
}
