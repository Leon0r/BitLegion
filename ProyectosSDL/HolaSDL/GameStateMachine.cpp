#include "GameStateMachine.h"



GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
	libera();
}

void GameStateMachine::popState(bool b) {
	if (!states.empty()) { //si la pila de estados no est� vacia
		if (b) deleteAndPopState(); //delete y pop
		else { states.pop(); actualStates.pop_back(); }//pop de la lista auxiliar
	}
}

void GameStateMachine::pushState(GameState* newState) {
	states.push(newState); //pushea un nuevo estado a la pila
	actualStates.push_back(newState); //push a la lista auxiliar
}

GameState* GameStateMachine::currentState() {
	if (!states.empty()) {
		return states.top(); //return del current state, util para SDLApp
	}
}

bool GameStateMachine::checkElement(GameState * state){
	list<GameState*>::iterator it = actualStates.begin();
	bool found = false;
	while (it != actualStates.end() && !found) { //comprueba si el estado est� dentro de la lista
		if (*it == state) {
			found = true;
		}
		it++;
	}
	return found;
}

void GameStateMachine::libera() {
	while (!states.empty()) {
		deleteAndPopState();
	}
}

void GameStateMachine::deleteAndPopState(){
	delete states.top();
	states.pop();
}
