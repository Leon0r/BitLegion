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

void GameState::handleEvent(SDL_Event &e) { //manda a los objetos del juego que detecten 
	bool handled = false;
	it = stage.begin();
	//list<GameObject*>::iterator shit;//Aux a cambiar?????
	//shit = stage.end();
	listhasChanged = false;
	while (!listhasChanged && it != stage.end()) {
		(*it)->handleInput(0, e);
		if (!listhasChanged) { //si borras un elemento, solo puede afectar aquí (se borra a traves de los componentes HandleInput)
			it++; //si no borras nada se incrementa
		}
	}
	//listhasChanged = false;
}

void GameState::render() {
	list<GameObject*>::const_reverse_iterator aux;
	for(aux = stage.rbegin(); aux != stage.rend(); aux++)
		(*aux)->render(0);
}

void GameState::deleteElement(GameObject* o) {
	it = stage.begin();
	bool encontrado = false;
	while (it != stage.end() && !encontrado) {
		if (*it == o) {
			encontrado = true;
			it = stage.erase(it);
			listhasChanged = true;
		}
		else {
			it++;
		}
	}
	delete o;
}