/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.setup.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:35:20 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 21:40:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

void	Game::loadGame() {

	//Sets _victory condition to false
	_victory = false;

	//It's the template for types of materia, so then we can create using the names
	_src = new MateriaSource();
	_src->learnMateria(new Ice());
	_src->learnMateria(new Cure());
	_src->learnMateria(new Fire());
	_src->learnMateria(new Thunder());

	//These are the characters that will use the materia
	_azrael = new Character("Azrael");
	_evanora = new Character("Evanora");
	_ghidorah = new Character("Ghidorah");

	//Set custom enemies HP
	_azrael->setHealth(AZRAEL_HP);
	_ghidorah->setHealth(GHIDORAH_HP);

	//Actually creates the materia from the templates made before
	//And equips them to the characters
	_evanora->equip(_src->createMateria("Thunder"));
	_evanora->equip(_src->createMateria("Thunder"));
	_evanora->equip(_src->createMateria("Thunder"));
	_evanora->equip(_src->createMateria("Cure"));
}

void	Game::firstEnemyType() {

	std::string	type = "Fire";

	if (_player->getMateriaType(0) == "Fire")
		type = "Ice";

	_azrael->equip(_src->createMateria(type));
	_azrael->equip(_src->createMateria(type));
	_azrael->equip(_src->createMateria(type));
	_azrael->equip(_src->createMateria("Cure"));

}

void	Game::equipDark() {

	((MateriaSource *)_src)->forgetMateria(0);
	_src->learnMateria(new Dark());

	_ghidorah->equip(_src->createMateria("Dark"));
	_ghidorah->equip(_src->createMateria("Dark"));
	_ghidorah->equip(_src->createMateria("Cure"));
	_ghidorah->equip(_src->createMateria("Cure"));
}
