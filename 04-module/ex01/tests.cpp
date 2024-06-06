/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:23:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/06 17:09:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

void	testBrainyCat(void) {

	println("\n  With the advance of technology, cats got smarter.");
		const Animal* catto = new Cat("Oreo");

	println("\n  It would still look like a cat and sound like a cat.");
		catto->makeSound();

	println("\n  But now, it would also think like a cat!");
		catto->getBrain().think("*I'm a cat, I'm a cat, I'm a cat...*");
		catto->getBrain().think("*Hmm... I'd love some tuna now!*");
		catto->getBrain().think("*Oh! A laser pointer!*");

	println("\n  The ideas were persistent, and the cat would remember them:");
		catto->getBrain().print();

	println("\n  But they were still short lived.");
		delete catto;

	next();
}

void	testBrainyDog(void) {

	println("  Not as much as cats, but dogs also got smarter.");
		const Animal* doggo = new Dog("Cocoa");

	println("\n  From the outside, not much had changed.");
		doggo->makeSound();

	println("\n  But its mind was full of ideas!");
		doggo->getBrain().think("*LICKMABALS*");
		doggo->getBrain().think("*My ears are scratching...*");
		doggo->getBrain().think("*When are the hoomans coming back?*");

	println("\n  If they weren't too many, it would remember them too.");
		doggo->getBrain().print();

	println("\n  Life span limited, still.");
		delete doggo;

	next();
}

void	testCloning(void) {

	println("  One day, a genious cat was born.");
		const Cat* biggie = new Cat("Max");

	println("\n  It honed unusually complex and deep thoughts.");
		biggie->getBrain().think("*Communism deprives no man of the power"
		" to appropriate the\n     products of society: all that it does is to "
		"deprive him of the power\n     to subjugate the labor of others by means"
		" of such appropriation.*");
		biggie->makeSound();

	println("\n  This " << biggie->getType() << " was unique, but would also perish."
		" So we decided to clone it.");
		const Cat* dolly = new Cat(*biggie);

	println("\n  Original " << biggie->getName() << " was amazing until the very end.");
		biggie->getBrain().think("*The proletarians have nothing to lose\n     but "
		"their chains. They have a world to win.*");
		biggie->makeSound();
		println("");
		delete biggie;

	println("\n  The clone was able to keep the core values of its predecessor.");
		dolly->getBrain().print();
		dolly->makeSound();

	println("\n  But it was also doomed.");
		delete dolly;

	next();
}

void	testAnimalArray(void) {
	int		amount = 10;

	println("  The word spread around and everyone wanted a pet,"
			" so we went full Ford on them!\n")
		const Animal	*zoo[amount];
		for (int i = 0; i < amount; i++) {
			int pet = i % 2;
			switch (pet) {
				case 0:
					zoo[i] = new Cat("Cat");
					zoo[i]->getBrain().think("*I'm hungry...*");
					break;
				case 1:
					zoo[i] = new Dog("Dog");
					zoo[i]->getBrain().think("*Hoomans!*");
					break;
			}
			println("");
		}

	next();

	println("  It was super noisy with all those pets around.\n");
		for (int i = 0; i < amount; i++) {
			zoo[i]->makeSound();
			println("");
		}

	next();

	println("  They made their families happy while they were alive."
			" We loved them all very much.\n");
		for (int i = 0; i < amount; i++) {
			delete zoo[i];
			println("");
		}
}

void	next(void) {
	println("\n  ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clear;
}
