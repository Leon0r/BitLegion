#pragma once
#include "GameState.h"

class Puzzle: public GameState
{
public:
	Puzzle() {};
	Puzzle(SDLApp* app) : GameState(app) {};
	~Puzzle();

	int id;
	virtual void searchId() {};
};

