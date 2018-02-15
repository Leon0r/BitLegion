#pragma once
#include "GameState.h"
#include "GameComponent.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"

//estado de prueba, con Alena moviendose por pantalla
class StatePrueba: public GameState
{
private:
	GameComponent* alena;//personaje del juego
public:
	StatePrueba() {}
	~StatePrueba() {}
	StatePrueba(SDLApp* app);
	//actualiza todos los objetos del estado
	virtual void update() { GameState::update(); }
	//pinta todos los objetos del estado
	virtual void render() { GameState::render(); }
};

