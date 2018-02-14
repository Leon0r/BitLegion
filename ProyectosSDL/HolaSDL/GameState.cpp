#include "GameState.h"



GameState::GameState()
{
}

void GameState::handleEvent(SDL_Event &e) { //manda a los objetos del juego que detecten eventos
	bool handled = false;
	for (GameObject* it : stage) {
		it->handleInput(0, e); 
	}
}