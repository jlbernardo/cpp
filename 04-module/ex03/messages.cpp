/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/06/10 16:44:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	enemyScream(ICharacter &enemy) {

	if (enemy.getName() == "Azrael")
		println(RED << "\n                            YOU'LL NEVER WIN, PEASANT!!! MWAHAHAHAHAHAHAHA\n");
	if (enemy.getName() == "Evanora")
		println(RED << "\n                            AZRAAAAA!!!   NOOOOO!!!   YOU'LL PAY, DWARF!!!!\n");
	if (enemy.getName() == "Ghidorah")
		println(RED << "\n                            RRRAAAAAAGRRWWWWWRWRWRWWW!!!!!!!!!!!!!!!!!!!!\n");
}

void	attackMessage(ICharacter &player, ICharacter &enemy, std::string &input) {

	battleScreen(player, enemy);

	println(WHT << "\n                                 Choose a magic slot to use, " << player.getName() << "!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clear;
}

void	retaliationMessage(ICharacter &player, ICharacter &enemy, std::string &input) {

	battleScreen(player, enemy);

	println(RED << "\n                                     " << enemy.getName() << "'s time to act!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clear;
	println("");
}

void	next(void) {
	println("\n            ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clear;
}


void	battleScreen(ICharacter &player, ICharacter &enemy) {

	int			enemy_hp = AZRAEL_HP;
	std::string	color;

	if (enemy.getMateriaType(0) == "Ice")
		color = CYN;
	else if (enemy.getMateriaType(0) == "Fire")
		color = RED;
	else if (enemy.getMateriaType(0) == "Thunder") {
		color = YLW;
		enemy_hp = EVANORA_HP;
	}
	else {
		color = PRP;
		enemy_hp = GHIDORAH_HP;
	}

	enemyScreen(enemy, color);

	if (enemy.getHealth() >= enemy_hp * 0.5)
		color = GRN;
	else if (enemy.getHealth() >= enemy_hp * 0.3)
		color = YLW;
	else
		color = RED;

	println(WHT << "                                                                           HP " << color << enemy.getHealth());
	println("            ╭─────────────────────────────────────╮");
	println("            │               " << std::setw(3) << player.getHealth() << "  HP               │");
	println("            │                                     │");
	println("            │ [1] " << player.getMateriaGem(0) << " " << std::left << std::setw(10) << player.getMateriaType(0)
													<< " [2] " << player.getMateriaGem(1) << " " << std::left << std::setw(10) << player.getMateriaType(1) << " │");
	println("            │                                     │");
	println("            │ [3] " << player.getMateriaGem(2) << " " << std::left << std::setw(10) << player.getMateriaType(2)
													<< " [4] " << player.getMateriaGem(3) << " " << std::left << std::setw(10) << player.getMateriaType(3) << " │");
	println("            ╰─────────────────────────────────────╯");
}

void	retryMessage(game &game, std::string &input) {

	println("");
	println("                 We will perish if you give up, but I understand if you can't take it anymore.");
	println("                 I think... Here, eat this, it should make you a little stronger for the next try.");
	println("                 We really need your help, " << game.me->getName() << ". Please, don't give up!\n");
	villager();
	println(WHT << "                 Your HP was increased greatly. You can [" << GRN << "R" << WHT << "]etry or ["
										<< RED << "G" << WHT << "]ive up.");
	println(WHT << "               ╭──────────────────────────────────────────────────────────────╯")
	std::cout << WHT << "               ╰─➤ " << DFL;

	while (input.empty() || (input != "R" && input != "G")) {
		getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
	}

}

void	rewardMessage(game &game, ICharacter &enemy, std::string &input) {

	println(WHT << "            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │                  " << GRN << "You have successfully defeated " << std::left << std::setw(8) << enemy.getName() << WHT << std::setw(17) << " " << "│");
	println(WHT << "            │                                                                          │");
	gemReward(enemy.getMateriaType(0));
	println(WHT << "            │      on one of your free slots or choose one of the occupied ones to     │");
	println(WHT << "            │   be replaced. If you don't want to equip this Materia, you can Skip it  │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [1] " << game.me->getMateriaGem(0) << " " << std::left << std::setw(15) << game.me->getMateriaType(0)
													<< " [2] " << game.me->getMateriaGem(1) << " " << std::left << std::setw(15) << game.me->getMateriaType(1) << "         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [3] " << game.me->getMateriaGem(2) << " " << std::left << std::setw(15) << game.me->getMateriaType(2)
													<< " [4] " << game.me->getMateriaGem(3) << " " << std::left << std::setw(15) << game.me->getMateriaType(3) << "         │");
	println(WHT << "            ├──────────────────────────────────────────────────────────────────────────╯");
	println(WHT << "            │")
	std::cout << WHT << "            ╰─➤ " << DFL;

	while (input.empty() || (input != "1" && input != "2" && input != "3" && input != "4" && input != "S" && input != "E")) {
		getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
	}

	if (input == "E")
		gameOver(game);
}

void	gemReward(std::string type) {

	if (type == "Ice") {
		println(WHT << "            │          An ❄️  Ice gem was dropped on the ground. You can equip it       │");
	}
	else if (type == "Fire") {
		println(WHT << "            │         A 🔥 Fire gem was dropped on the ground. You can equip it        │");
	}
	else if (type == "Thunder") {
		println(WHT << "            │        A ⚡ Thunder gem was dropped on the ground. You can equip it      │");
	}
	else if (type == "Dark") {
		println(WHT << "            │         A 🌑 Dark gem was dropped on the ground. You can equip it        │");
	}
}
