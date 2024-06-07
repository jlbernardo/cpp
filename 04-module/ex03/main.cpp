/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:00:23 by julberna          #+#    #+#             */
/*   Updated: 2024/06/07 00:37:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

int main(void)
{
	//It's the template for types of materia, so then we can create using the names
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Thunder());

	//These are the characters that will use the materia
	ICharacter* me = new Character(name());
	ICharacter* azrael = new Character("Azrael");
	ICharacter* evanora = new Character("Evanora");

	//Actually creates the materia from the templates made before
	me->equip(src->createMateria("Ice"));
	me->equip(src->createMateria("Cure"));
	// me->equip(src->createMateria("Fire"));
	// me->equip(src->createMateria("Thunder"));

	azrael->equip(src->createMateria("Ice"));
	azrael->equip(src->createMateria("Cure"));
	azrael->equip(src->createMateria("Fire"));
	azrael->equip(src->createMateria("Thunder"));

	fight(*me, *azrael);

	//Deletes the resources used in the program
	delete me;
	delete evanora;
	delete azrael;
	delete src;

	return (EXIT_SUCCESS);
}
