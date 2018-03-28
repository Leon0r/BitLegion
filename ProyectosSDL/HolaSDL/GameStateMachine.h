#pragma once
#include "checkML.h"
#include "GameState.h"
#include <stack>

class GameStateMachine
{
private:
	stack <GameState*> states;
public:
	GameStateMachine();
	~GameStateMachine();
	void popState(bool b = true);
	void pushState(GameState* newState);
	GameState* currentState();
	void libera();
};

