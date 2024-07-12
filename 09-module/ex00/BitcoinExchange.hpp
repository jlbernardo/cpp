/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:05 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 01:15:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <cstring>
# include <utility>
# include <fstream>
# include <sstream>
# include <iostream>
# include "general.hpp"

# define FIRST	1
# define SECOND	2

typedef std::map<std::string, float>::const_iterator mapIter;

class BitcoinExchange {

private:
	static std::ifstream				_csv;
	static std::map<std::string, float>	_data;

						BitcoinExchange(void);
						~BitcoinExchange(void);
						BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange		&operator=(const BitcoinExchange &rhs);

public:
	static void			loadCSV(void);
	static void			printCSV(void);
};

#endif
