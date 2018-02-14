#pragma once
#include "GameState.h"
#include "GameComponent.h"

class StatePrueba: public GameState
{
public:
	StatePrueba();
	~StatePrueba();
	StatePrueba(SDLApp* app);
	virtual void update() { GameState::update(); }
};

