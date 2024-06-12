#include "Game.hpp"

Game::Game(void) {
}

Game::Game(Game const &src) {
	*this = src;
}

Game::~Game(void) {
}

Game	&Game::operator=(Game const &rhs) {
	if (this != &rhs) {
		this->_victory = rhs._victory;
		this->_ghidorah = rhs._ghidorah;
		this->_evanora = rhs._evanora;
		this->_azrael = rhs._azrael;
		this->_player = rhs._player;
		this->_src = rhs._src;
	}
	return (*this);
}
