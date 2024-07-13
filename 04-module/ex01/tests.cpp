/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:23:41 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 17:06:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

void	testBrainyCat(void) {

	println("\n  With the advance of technology, cats got smarter.");
		Cat* catto = new Cat("Oreo");

	println("\n  It would still look like a cat and sound like a cat.");
		catto->makeSound();

	println("\n  But now, it would also think like a cat!");
		catto->think("*I'm a cat, I'm a cat, I'm a cat...*");
		catto->think("*Hmm... I'd love some tuna now!*");
		catto->think("*Oh! A laser pointer!*");

	println("\n  The ideas were persistent, and the cat would remember them:");
		catto->print();

	println("\n  But they were still short lived.");
		delete catto;

	next();
}

void	testBrainyDog(void) {

	println("  Not as much as cats, but dogs also got smarter.");
		Dog* doggo = new Dog("Cocoa");

	println("\n  From the outside, not much had changed.");
		doggo->makeSound();

	println("\n  But its mind was full of ideas!");
		doggo->think("*LICKMABALS*");
		doggo->think("*My ears are scratching...*");
		doggo->think("*When are the hoomans coming back?*");

	println("\n  If they weren't too many, it would remember them too.");
		doggo->print();

	println("\n  Life span limited, still.");
		delete doggo;

	next();
}

void	testCloning(void) {

	println("  One day, a genious cat was born.");
		Cat* biggie = new Cat("Max");

	println("\n  It honed unusually complex and deep thoughts.");
		biggie->think("*Communism deprives no man of the power"
		" to appropriate the\n     products of society: all that it does is to "
		"deprive him of the power\n     to subjugate the labor of others by means"
		" of such appropriation.*");
		biggie->makeSound();

	println("\n  This " << biggie->getType() << " was unique, but would also perish."
		" So we decided to clone it.");
		Cat* dolly = new Cat(*biggie);

	println("\n  Original " << biggie->getName() << " was missed dearly.");
		biggie->makeSound();
		println("");
		delete biggie;

	println("\n  But the clone was able to keep the core values of its predecessor.");
		dolly->print();
		dolly->makeSound();

	println("\n  It lasted while it lasted, anyhow...");
		delete dolly;

	next();
}

void	testAnimalArray(void) {
	int		amount = 10;

	println("  The word spread around and everyone wanted a pet,"
			" so we went full Ford on them!\n")
	Animal	*zoo[amount];
	for (int i = 0; i < amount; i++) {
		int pet = i % 2;
		switch (pet) {
			case 0:
				zoo[i] = new Cat("Cat");
				reinterpret_cast<Cat *>(zoo[i])->think("*I'm hungry...*");
				break;
			case 1:
				zoo[i] = new Dog("Dog");
				reinterpret_cast<Dog *>(zoo[i])->think("*Hoomans!*");
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
	clean;
}
