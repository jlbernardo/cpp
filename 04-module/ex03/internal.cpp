/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:40 by julberna          #+#    #+#             */
/*   Updated: 2024/06/08 23:59:58 by julberna         ###   ########.fr       */
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

	game.src->forgetMateria(0);
	game.src->learnMateria(new Dark());

	game.ghidorah->equip(game.src->createMateria("Dark"));
	game.ghidorah->equip(game.src->createMateria("Dark"));
	game.ghidorah->equip(game.src->createMateria("Cure"));
	game.ghidorah->equip(game.src->createMateria("Cure"));
}

void	gameOver(game &game) {
	delete game.me;
	delete game.src;
	delete game.azrael;
	delete game.evanora;
	delete game.ghidorah;
	exit(EXIT_SUCCESS);
}
