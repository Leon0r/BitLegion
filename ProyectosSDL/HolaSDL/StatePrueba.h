#pragma once
#include "GameState.h"
#include "GameComponent.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"

class StatePrueba: public GameState
{
private:
	GameComponent* detective;
public:
	StatePrueba();
	~StatePrueba();
	StatePrueba(SDLApp* app);
	virtual void update() { GameState::update(); }
	virtual void render() { GameState::render(); }
};

