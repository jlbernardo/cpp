/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:05 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 23:32:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <list>
# include <time.h>
# include <iomanip>
# include <cstring>
# include <utility>
# include <fstream>
# include <sstream>
# include <iostream>
# include "general.hpp"

typedef std::map<std::string, float>::const_iterator mapIter;

typedef struct exchange_s {
	std::string	rateDate;
	std::string	userDate;
	float		rateValue;
	float		userValue;
	float		tradedValue;
}				exchange_t;

class BitcoinExchange {

private:
	exchange_t						_trade;
	std::ifstream					_csv;
	std::ifstream					_input;
	std::map<std::string, float>	_data;


						BitcoinExchange(void);
						BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange		&operator=(const BitcoinExchange &rhs);

public:
						BitcoinExchange(char *input);
						~BitcoinExchange(void);

	void				loadCSV(void);
	void				analyzeInput(void);

	bool				dateIsValid(void);
	bool				valueIsValid(void);
	bool				formatIsValid(std::string entry);

	void				calculateExchange(void);
	void				printExchange(void);
};

#endif
