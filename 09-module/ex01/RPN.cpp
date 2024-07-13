/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:02:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 05:01:23 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(std::string input) : _input(input) {
}

RPN::~RPN(void) {
}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN	&RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->_input = rhs._input;
	}
	return (*this);
}

void	RPN::calculate(void) {
	std::string			token;
	std::stringstream	ss(this->_input);

	this->print();
	next;

	while (std::getline(ss, token, ' ')) {
		int			a = 0;
		int			b = 0;
		long int	value = 0;

		if (std::isdigit(token[0])) {
			value = std::strtol(token.c_str(), 0, 10);
			this->_abacus.push(value);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (this->_abacus.size() > 1) {
				b = this->_abacus.top();
				this->_abacus.pop();
				a = this->_abacus.top();
				this->_abacus.pop();
			}
			else {
				println(RED << "\n Error: not enough tokens for operation!");
				return ;
			}

			if (token == "+") {
				this->_abacus.push(a + b);
			}
			else if (token == "-") {
				this->_abacus.push(a - b);
			}
			else if (token == "*") {
				this->_abacus.push(a * b);
			}
			else if (token == "/") {
				if (b == 0) {
					println(RED << "\n Error: cannot divide by zero!");
					return ;
				}
				this->_abacus.push(a / b);
			}
		}
		else {
			println(RED << "\n Error: unrecognized token!");
			return ;
		}

		if (this->_input.length() == 1) {
			this->_input.clear();
			break ;
		}
		this->_input = this->_input.substr(this->_input.find_first_of(" \t") + 1);
		this->print();
		next;
	}
	if (this->_abacus.size() == 1) {
		println(GRN << std::endl << " result: " << this->_abacus.top() << std::endl);
		this->print();
		return ;
	}
	println(RED << "\n Error: invalid input!");
}

void	RPN::print(void) {

	unsigned int						width = this->longestNumber();
	std::stack< int, std::list<int> >	copy(this->_abacus);

	if (!this->_input.empty())
		println(PRP << std::endl << "    " << this->_input << std::endl);
	println(WHT << "  stack: ╭ " << std::setw(width + 4) << " ╮");
	while (!copy.empty()) {
		println(WHT << "         │ " << std::setw(width) << copy.top() << " │");
		copy.pop();
	}
	println(WHT << "         ╰ " << std::setw(width + 4) << " ╯");
}

int		RPN::longestNumber(void) {

	unsigned int						longest = 0;
	std::stack< int, std::list<int> >	copy(this->_abacus);

	while (!copy.empty()) {
		std::stringstream	ss;

		ss << copy.top();
		if (ss.str().size() > longest)
			longest = ss.str().size();

		copy.pop();
	}

	return (longest);
}
