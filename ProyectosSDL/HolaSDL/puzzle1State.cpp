#include "puzzle1State.h"

Puzzle1State::Puzzle1State(SDLApp * game, GameState * previousState): GameState(game), previousState(previousState)
{
}

void Puzzle1State::handleEvent(SDL_Event & event)
{
	it = stage.begin(); //En principio pongo el blucle simple, si vemos que hay problemas al borrar items metemos el bucle del juego principal
	while (it != stage.end()) {
		(*it)->handleInput(0, event);
		it++;
	}
}

void Puzzle1State::render()
{
	list<GameObject*>::const_reverse_iterator aux;
	for (aux = stage.rbegin(); aux != stage.rend(); aux++)
		(*aux)->render(0);
}

void Puzzle1State::update()
{
	startTime = SDL_GetTicks();
	for (GameObject* it : stage) { it->update(0); }//Recorrido lista actores
	// Calcula el tiempo del update del playState
	frameTime = SDL_GetTicks() - startTime;
	// Si no ha pasado el tiempo definido en FRAME_RATE, hay delay de lo que falta
	if (frameTime<FRAME_RATE) SDL_Delay(FRAME_RATE - frameTime);

	if (gameSolved()) {
		//Enviamos msg puzzle resuleto
		//volvemos al estado anterior 
	}
}

bool Puzzle1State::gameSolved()
{
	bool solved = false;
	//Comprobacion puzzle solucionado
	if (false) solved = true;

	return solved;
}
