/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:02:02 by julberna          #+#    #+#             */
/*   Updated: 2024/07/13 14:44:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(std::string input) : _input(input), _operate(input) {
	this->_operate.erase(
		std::remove_if(this->_operate.begin(), this->_operate.end(), ::isspace),
						this->_operate.end());
	this->_input.erase(
		std::remove_if(this->_input.begin(), this->_input.end(), ::isspace),
						this->_input.end());
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

	this->print();
	next;

	for (std::string::iterator it = this->_operate.begin(); it != this->_operate.end(); it++) {
		int			a = 0;
		int			b = 0;
		long int	value = 0;

		if (std::isdigit(*it)) {
			value = static_cast<int>(*it) - '0';
			this->_abacus.push(value);
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') {
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

			switch (*it) {
				case '+':
					this->_abacus.push(a + b);
					break ;
				case '-':
					this->_abacus.push(a - b);
					break ;
				case '*':
					this->_abacus.push(a * b);
					break ;
				case '/':
					if (b == 0) {
						println(RED << "\n Error: cannot divide by zero!");
						return ;
					}
					this->_abacus.push(a / b);
					break ;
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
		this->_input.erase(this->_input.begin(), this->_input.begin() + 1);
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

	if (!this->_input.empty()) {
		std::cout << PRP << std::endl << "    " << std::flush;
		for (std::string::iterator it = this->_input.begin(); it != this->_input.end(); it++)
			std::cout << *it << " " << std::flush;
		println("\n");
	}
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
