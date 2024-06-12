/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:35:20 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 21:55:09 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	loadGame(game &game) {

	//Sets victory condition to false
	game.victory = false;

	//It's the template for types of materia, so then we can create using the names
	game.src = new MateriaSource();
	game.src->learnMateria(new Ice());
	game.src->learnMateria(new Cure());
	game.src->learnMateria(new Fire());
	game.src->learnMateria(new Thunder());

	//These are the characters that will use the materia
	game.azrael = new Character("Azrael");
	game.evanora = new Character("Evanora");
	game.ghidorah = new Character("Ghidorah");

	//Set custom enemies HP
	game.azrael->setHealth(AZRAEL_HP);
	game.ghidorah->setHealth(GHIDORAH_HP);

	//Actually creates the materia from the templates made before
	//And equips them to the characters
	game.evanora->equip(game.src->createMateria("Thunder"));
	game.evanora->equip(game.src->createMateria("Thunder"));
	game.evanora->equip(game.src->createMateria("Cure"));
	game.evanora->equip(game.src->createMateria("Cure"));
}

void	firstEnemyType(game &game) {

	std::string	type = "Fire";

	if (game.me->getMateriaType(0) == "Fire")
		type = "Ice";

	game.azrael->equip(game.src->createMateria(type));
	game.azrael->equip(game.src->createMateria(type));
	game.azrael->equip(game.src->createMateria("Cure"));
	game.azrael->equip(game.src->createMateria("Cure"));

}

void	equipDark(game &game) {

	((MateriaSource *)game.src)->forgetMateria(0);
	game.src->learnMateria(new Dark());

	game.ghidorah->equip(game.src->createMateria("Dark"));
	game.ghidorah->equip(game.src->createMateria("Dark"));
	game.ghidorah->equip(game.src->createMateria("Cure"));
	game.ghidorah->equip(game.src->createMateria("Cure"));
}
