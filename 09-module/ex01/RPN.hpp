/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:01:26 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 04:40:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <stack>
# include <sstream>
# include <iomanip>
# include "general.hpp"

class RPN {

private:
	std::string							_input;
	std::stack< int, std::list<int> >	_abacus;

				RPN(void);
				RPN(const RPN &copy);
	RPN			&operator=(const RPN &rhs);

public:
				RPN(std::string input);
				~RPN(void);

	void		calculate(void);
	void		print(void);
	int			longestNumber(void);
};

#endif
