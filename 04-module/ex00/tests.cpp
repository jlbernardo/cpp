/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:23:41 by julberna          #+#    #+#             */
/*   Updated: 2024/06/05 21:28:22 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

void	testAnimalBaseClass(void) {

	println("\n  In the beginning, there was only Animal...");
		const Animal* meta = new Animal();

	println("\n  It didn't make any particular sound:");
		meta->makeSound();

	println("\n  And it would just go out unnoticed.");
		delete meta;

	next();
}

void	testCatClass(void) {

	println("  Descending from Animal, we had Cat.");
		const Animal* catto = new Cat();

	println("\n  It looked like a cat and sounded like a cat.");
		catto->makeSound();

	println("\n  So, of course, its type was: " << catto->getType());

	println("\n  And it would just walk away when bored.");
		delete catto;

	next();
}

void	testDogClass(void) {

	println("  Also descending from Animal, we had Dog.");
		const Animal* doggo = new Dog();

	println("\n  It looked very dogly and sounded very dogly:")
		doggo->makeSound();

	println("\n  Unsurprisingly, its type was: " << doggo->getType());

	println("\n  And it would often run away chasing a ball.");
		delete doggo;

	next();
}

void	testWrongAnimalClass(void) {

	println("  One day, however, resulting from an unconventional experiment,"
			"\n  Animal mutated and gave origin to... Something weird.")
		const WrongAnimal* weirdo = new WrongAnimal();

	println("\n  It looked like Animal, but would make funny sounds...");
		weirdo->makeSound();

	println("\n  Sadly, it would never live very long.");
		delete weirdo;

	next();
}

void	testWrongCatClass(void) {

	println("  The funniest thing was when this other creature came up.")
		const WrongAnimal* wrongo = new WrongCat();

	println("\n  Its type was \"" << wrongo->getType() <<
			"\", but looked wrong and would sound even wronger.");
		wrongo->makeSound();

	println("\n  Luckily, it was put out of its misery before it caused too much trouble.")
		delete wrongo;
}

void	next(void) {
	println("\n  ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clear;
}
