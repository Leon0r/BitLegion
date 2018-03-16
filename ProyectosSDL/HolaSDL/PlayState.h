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
#include "Scene.h"
#include "json.hpp"
#include "MainCharacter.h"

//estado de prueba, con Alena moviendose por pantalla
class PlayState: public GameState
{
private:
	MainCharacter* alena;//personaje del juego
	ObjectList* list;
	ShortCut* shortcut;
	std::list<GameObject*> collision;
	const Resources* resources = app->getResources();//recursos del juego
	vector<Scene*> scenes;
	int currentScene = 0;

public:
	PlayState() {}
	~PlayState();
	PlayState(SDLApp* app);
	MainCharacter* getMainPj() { return alena; }
	ShortCut* getShortCut(){ return shortcut; }
	void creaInventario() { app->getStateMachine()->pushState(new Inventory(app, list, this, shortcut)); }
	ObjectList* getList() { return list; };//prueba, no deberia estar aqui
	vector<Scene*> getScenes(){ return scenes; };
	void swapScene(int nextScene);	
};

