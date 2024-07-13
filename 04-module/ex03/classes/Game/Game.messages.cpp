/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.messages.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:38:59 by julberna          #+#    #+#             */
/*   Updated: 2024/07/12 17:06:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

void	Game::enemyScream(Character &enemy) {

	if (enemy.getName() == "Azrael")
		println(RED << "\n                            YOU'LL NEVER WIN, PEASANT!!! MWAHAHAHAHAHAHAHA\n");
	if (enemy.getName() == "Evanora")
		println(RED << "\n                            AZRAAAAA!!!   NOOOOO!!!   YOU'LL PAY, DWARF!!!!\n");
	if (enemy.getName() == "Ghidorah")
		println(RED << "\n                            RRRAAAAAAGRRWWWWWRWRWRWWW!!!!!!!!!!!!!!!!!!!!\n");
}

void	Game::attackMessage(Character &enemy, std::string &input) {

	battleScreen(enemy);

	println(WHT << "\n                                 Choose a magic slot to use, " << _player->getName() << "!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clean;
}

void	Game::retaliationMessage(Character &enemy, std::string &input) {

	battleScreen(enemy);

	println(RED << "\n                                     " << enemy.getName() << "'s time to act!");
	println(WHT << "               ╭────────────────────────────────────────────────────────────────────╯");
	std::cout << WHT << "               ╰─➤ " << DFL;

	std::getline(std::cin, input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = (char)toupper(*it);

	clean;
	println("");
}

void	Game::next(void) {
	println("\n            ᵖʳᵉˢˢ ᵃⁿʸ ᵏᵉʸ ᵗᵒ ᶜᵒⁿᵗⁱⁿᵘᵉ");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clean;
}


void	Game::battleScreen(Character &enemy) {

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
	println("            │               " << std::setw(3) << _player->getHealth() << "  HP               │");
	println("            │                                     │");
	println("            │ [1] " << _player->getMateriaGem(0) << " " << std::left << std::setw(10) << _player->getMateriaType(0)
													<< " [2] " << _player->getMateriaGem(1) << " " << std::left << std::setw(10) << _player->getMateriaType(1) << " │");
	println("            │                                     │");
	println("            │ [3] " << _player->getMateriaGem(2) << " " << std::left << std::setw(10) << _player->getMateriaType(2)
													<< " [4] " << _player->getMateriaGem(3) << " " << std::left << std::setw(10) << _player->getMateriaType(3) << " │");
	println("            ╰─────────────────────────────────────╯");
}

void	Game::retryMessage(std::string &input) {

	println("");
	println("                 We will perish if you give up, but I understand if you can't take it anymore.");
	println("                 I think... Here, eat this, it should make you a little stronger for the next try.");
	println("                 We really need your help, " << _player->getName() << ". Please, don't give up!\n");
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

void	Game::rewardMessage(Character &enemy, std::string &input) {

	println(WHT << "            ╭──────────────────────────────────────────────────────────────────────────╮");
	println(WHT << "            │                  " << GRN << "You have successfully defeated " << std::left << std::setw(8) << enemy.getName() << WHT << std::setw(17) << " " << "│");
	println(WHT << "            │                                                                          │");
	gemReward(enemy.getMateriaType(0));
	println(WHT << "            │      on one of your free slots or choose one of the occupied ones to     │");
	println(WHT << "            │   be replaced. If you don't want to equip this Materia, you can Skip it  │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [1] " << _player->getMateriaGem(0) << " " << std::left << std::setw(15) << _player->getMateriaType(0)
													<< " [2] " << _player->getMateriaGem(1) << " " << std::left << std::setw(15) << _player->getMateriaType(1) << "         │");
	println(WHT << "            │                                                                          │");
	println(WHT << "            │                    [3] " << _player->getMateriaGem(2) << " " << std::left << std::setw(15) << _player->getMateriaType(2)
													<< " [4] " << _player->getMateriaGem(3) << " " << std::left << std::setw(15) << _player->getMateriaType(3) << "         │");
	println(WHT << "            ├──────────────────────────────────────────────────────────────────────────╯");
	println(WHT << "            │")
	std::cout << WHT << "            ╰─➤ " << DFL;

	while (input.empty() || (input != "1" && input != "2" && input != "3" && input != "4" && input != "S" && input != "E")) {
		getline(std::cin, input);
		for (std::string::iterator it = input.begin(); it != input.end(); it++)
			*it = (char)toupper(*it);
	}

	if (input == "E")
		gameOver();
}

void	Game::gemReward(std::string type) {

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
