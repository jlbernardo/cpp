/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:29:38 by julberna          #+#    #+#             */
/*   Updated: 2024/06/11 20:15:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpg.hpp"

void	villager(void) {
	println(GRN << "                                               ***");
	println(GRN << "                                             *******");
	println(GRN << "                                            *********");
	println(GRN << "                                         /\\* ### ### */\\");
	println(GRN << "                                         |    @ / @    |");
	println(GRN << "                                         \\/\\    ^    /\\/");
	println(GRN << "                                            \\  ===  /");
	println(GRN << "                                             \\_____/");
	println(GRN << "                                              _|_|_");
	println(GRN << "                                           *$$$$$$$$$*\n\n");
}

void	enemyScreen(Character &enemy, std::string color) {
	if (enemy.getName() == "Azrael") {
		println(WHT << "                                                         " << color << "                 /\\");
		println(WHT << "                                                         " << color << "                 ||");
		println(WHT << "                                   /^\\                  " << color << "    ____ (((+))) _||_");
		println(WHT << "                              /\\   \"V\"                " << color << "     /.--.\\  .-.  /.||.\\");
		println(WHT << "                             /__\\   I                   " << color << "  /.,   \\\\(0.0)// || \\\\");
		println(WHT << "                            //..\\\\  I                  " << color << "  /;`\";/\\ \\\\|m|//  ||  ;\\");
		println(WHT << "                            \\].`[/  I                   " << color << " |:   \\ \\__`:`____||__:|");
		println(WHT << "                            /l\\/j\\  (]                 " << color << "  |:    \\__ \\T/ (@~)(~@)|");
		println(WHT << "                           /. ~~ ,\\/I                   " << color << " |:    _/|     |\\_\\/  :|");
		println(WHT << "                           \\\\L__j^\\/I                 " << color << "   |:   /  |     |  \\   :|");
		println(WHT << "                            \\/--v}  I                   " << color << " |'  /   |     |   \\  '|");
		println(WHT << "                            |    |  I                    " << color << " \\_/    |     |    \\_/");
		println(WHT << "                            |    |  I                    " << color << "        |     |");
		println(WHT << "                            |    l  I                    " << color << "        |_____|");
		println(WHT << "                          _/j  L l\\_!                   " << color << "         |_____|");
	}
	else if (enemy.getName() == "Evanora") {
		println(WHT << "                                                         " << color << "        w*W*W*W*w");
		println(WHT << "                                                         " << color << "         \\\".\".\"/");
		println(WHT << "                                                         " << color << "          //`\\\\");
		println(WHT << "                                                         " << color << "         (/a a\\)");
		println(WHT << "                                                         " << color << "         (\\_-_/) ");
		println(WHT << "                                                         " << color << "        .-~'='~-.");
		println(WHT << "                                                         " << color << "       /`~`\"Y\"`~`\\");
		println(WHT << "                                   /^\\                  " << color << "       / /(_ * _)\\ \\");
		println(WHT << "                              /\\   \"V\"                " << color << "        / /  )   (  \\ \\");
		println(WHT << "                             /__\\   I                   " << color << "      \\ \\_/\\_//\\_/ / ");
		println(WHT << "                            //..\\\\  I                  " << color << "        \\/_) '*' (_\\/");
		println(WHT << "                            \\].`[/  I                   " << color << "         |       |");
		println(WHT << "                            /l\\/j\\  (]                 " << color << "          |       |");
		println(WHT << "                           /. ~~ ,\\/I                   " << color << "         |       |");
		println(WHT << "                           \\\\L__j^\\/I                 " << color << "           |       |");
		println(WHT << "                            \\/--v}  I                   " << color << "         |       |");
		println(WHT << "                            |    |  I                    " << color << "        |       |");
		println(WHT << "                            |    |  I                    " << color << "        |       |");
		println(WHT << "                            |    l  I                    " << color << "        |       |");
		println(WHT << "                          _/j  L l\\_!                   " << color << "         w*W*W*W*w");
	}
	else if (enemy.getName() == "Ghidorah") {
		println(WHT << "                                                         " << color << " <>=======() ");
		println(WHT << "                                                         " << color << "(/\\___   /|\\\\          ()==========<>_");
		println(WHT << "                                   /^\\                  " << color << "      \\_/ | \\\\        //|\\   ______/ \\)");
		println(WHT << "                              /\\   \"V\"                " << color << "        \\_|  \\      // | \\_/");
		println(WHT << "                             /__\\   I                   " << color << "          \\|\\/|\\_   //  /\\/");
		println(WHT << "                            //..\\\\  I                  " << color << "           (oo)\\ \\_//  /");
		println(WHT << "                            \\].`[/  I                   " << color << "          //_/\\_\\/ /  |");
		println(WHT << "                            /l\\/j\\  (]                 " << color << "         @@/  |=\\  \\  |");
		println(WHT << "                           /. ~~ ,\\/I                   " << color << "              \\_=\\_ \\ |");
		println(WHT << "                           \\\\L__j^\\/I                 " << color << "                \\==\\ \\|\\_ ");
		println(WHT << "                            \\/--v}  I                   " << color << "             __(\\===\\(  )\\");
		println(WHT << "                            |    |  I                    " << color << "            (((~) __(_/   |");
		println(WHT << "                            |    |  I                    " << color << "                 (((~) \\  /");
		println(WHT << "                            |    l  I                    " << color << "                 ______/ /");
		println(WHT << "                          _/j  L l\\_!                   " << color << "                 '------'");
	}
}
