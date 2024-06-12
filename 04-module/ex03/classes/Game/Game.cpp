#include "Game.hpp"

Game::Game(void) {
}

Game::~Game(void) {
}

Game::Game(Game const &rhs) {
	*this = rhs;
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

Game	&Game::getInstance() {
	static Game instance;
	return (instance);
}

void	Game::run(void) {

	this->loadGame();
	this->getName();
	this->getType();
	this->giveGift();
	this->battle();
	this->ending();
}
