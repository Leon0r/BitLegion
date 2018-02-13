#pragma once
#include "GameState.h"
#include "GOPrueba.h"

class StatePrueba: public GameState
{
public:
	StatePrueba();
	~StatePrueba();
	StatePrueba(SDLApp* app) : GameState(app) { GOPrueba* prueba = new GOPrueba('a'); stage.push_back(prueba); };
	virtual void update() { GameState::update(); }
};

