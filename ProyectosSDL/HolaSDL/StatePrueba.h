#pragma once
#include "GameState.h"
#include "MainCharacter.h"
#include "ItemInventario.h"


//estado de prueba, con Alena moviendose por pantalla
class StatePrueba: public GameState
{
private:
	Entity* alena;//personaje del juego
	ObjectList* list;
public:
	StatePrueba() {}
	~StatePrueba() {}
	StatePrueba(SDLApp* app);
	//actualiza todos los objetos del estado
	virtual void update() { GameState::update(); }
	//pinta todos los objetos del estado
	virtual void render() { GameState::render(); }
	Entity* getMainPj() { return alena; }
	ObjectList* getList() { return list; };//prueba, no deberia estar aqui
	
};

