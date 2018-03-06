#pragma once
#include "GameState.h"
#include "MainCharacter.h"
#include "ColisionableObject.h"
#include "ItemInventario.h"
#include "Entity.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "Resources.h"
#include "ShortCut.h"

//estado de prueba, con Alena moviendose por pantalla
class StatePrueba: public GameState
{
private:
	Entity* alena;//personaje del juego
	ObjectList* list;
	ShortCut* shortcut;
	std::list<GameObject*> collision;
	const Resources* resources = app->getResources();//recursos del juego
public:
	StatePrueba() {}
	~StatePrueba() {}
	StatePrueba(SDLApp* app);
	//actualiza todos los objetos del estado
	virtual void update() { GameState::update(); }
	//pinta todos los objetos del estado
	virtual void render() { GameState::render(); }
	Entity* getMainPj() { return alena; }
	ShortCut* getShortCut(){ return shortcut; }
	void creaInventario(){app->getStateMachine()->pushState(new Inventory(app, list, ItemInventario::getCoef(), shortcut->getMatriz())); }
	ObjectList* getList() { return list; };//prueba, no deberia estar aqui
};

