/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:50 by julberna          #+#    #+#             */
/*   Updated: 2024/05/24 19:05:49 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "ClapTrap.hpp"

void	waitAndClean(void);
void	destructionMessage(void);
void	constructionMessage(void);
void	fight(ClapTrap &attacker, ClapTrap &defender);
void	action(ClapTrap &attacker, ClapTrap &defender);
void	printScreen(ClapTrap &attacker, ClapTrap &defender);

#endif
