#pragma once
#include "GameState.h"
#include "Entity.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"

//estado de prueba, con Alena moviendose por pantalla
class StatePrueba: public GameState
{
private:
	Entity* alena;//personaje del juego
	Entity* object;//personaje del juego
	list<GameObject*> collision;
public:
	StatePrueba() {}
	~StatePrueba() {}
	StatePrueba(SDLApp* app);
	//actualiza todos los objetos del estado
	virtual void update() { GameState::update(); }
	//pinta todos los objetos del estado
	virtual void render() { GameState::render(); }
};

