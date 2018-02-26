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

#include "Scene.h"

//estado de prueba, con Alena moviendose por pantalla
class PlayState: public GameState
{
private:
	Entity* alena;//personaje del juego
	ObjectList* list;
	std::list<GameObject*> collision;
	const Resources* resources = app->getResources();//recursos del juego
	
	vector<Scene*> scenes;
	int currentScene = 0;
	virtual void handleEvent(SDL_Event &e);

public:
	PlayState() {}
	~PlayState() {}
	PlayState(SDLApp* app);
	//actualiza todos los objetos del estado
	virtual void update() { GameState::update(); }
	//pinta todos los objetos del estado
	virtual void render() { GameState::render(); }
	Entity* getMainPj() { return alena; }
	ObjectList* getList() { return list; };//prueba, no deberia estar aqui
	vector<Scene*> getScenes(){ return scenes; };
	void swapScene(int nextScene);
};

