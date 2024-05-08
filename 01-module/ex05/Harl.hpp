/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:30 by julberna          #+#    #+#             */
/*   Updated: 2024/05/08 10:42:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <fstream>
# include <iostream>
# include "general.hpp"

# define MAX_OPTIONS	4	// Maximum number of complaint levels

/**
 * #### Harl class, the complainer.
 */
class Harl {

public:
	/**
	 * @brief Displays a complaint on the screen, depending on the level.
	 * @param level The level of the complaint.
	 */
	void	complain(std::string level);

private:
	/**
	 * @brief These messages contain extensive information.
	 * They are helpful for tracing program execution
	 * in a production environment.
	 */
	void	info(void);

	/**
	 * @brief Debug messages contain contextual information.
	 * They are mostly used for problem diagnosis.
	 */
	void	debug(void);

	/**
	 * @brief These messages indicate an unrecoverable error has occurred.
	 * This is usually a critical issue that requires manual intervention.
	 */
	void	error(void);

	/**
	 * @brief Warning messages indicate a potential issue in the system.
	 * However, it can be handled or ignored.
	 */
	void	warning(void);
};

/**
 * @brief Reads from the appropriate file and shows Harl on your screen.
 * @param file Type of message.
 */
void	bubble(std::string file);

/**
 * @brief Initial Harl message, offers options to choose from.
 * @param input User's choice.
 */
void	prompt(std::string &input);

#endif
