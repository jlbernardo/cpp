/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:54:29 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 23:59:45 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPG_HPP
# define RPG_HPP

# include "IMateriaSource.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "Fire.hpp"
# include "Thunder.hpp"
# include "Character.hpp"
# include "general.hpp"
# include <limits>
# include <string>
# include <iomanip>


std::string	name(void);
void		next(void);
void		attack(ICharacter &player, ICharacter &enemy, std::string &input);
void		opponentsTurn(ICharacter &player, ICharacter &enemy, std::string &input);
void		printScreen(ICharacter &player, ICharacter &enemy);
void		retaliation(ICharacter &player, ICharacter &enemy);
void		fight(ICharacter &player, ICharacter &enemy);

#endif
