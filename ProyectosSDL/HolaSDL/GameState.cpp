#include "GameState.h"

GameState::GameState()
{
}

//manda a los objetos del estado update
void GameState::update() {
	startTime = SDL_GetTicks();

	for (GameObject* it : stage) { it->update(0); }

	// Calcula el tiempo del update del playState
	frameTime = SDL_GetTicks() - startTime;

	// Si no ha pasado el tiempo definido en FRAME_RATE, hay delay de lo que falta
	if (frameTime<FRAME_RATE) SDL_Delay(FRAME_RATE - frameTime);
}

void GameState::handleEvent(SDL_Event &e) { //manda a los objetos del juego que detecten eventos
	bool handled = false;
	for (GameObject* it : stage) {
		it->handleInput(0, e); 
	}
}