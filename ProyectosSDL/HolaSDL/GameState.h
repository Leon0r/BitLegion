#pragma once
#include "GameObject.h"
#include "SDLApp.h"
#include <list>


class GameState
{
protected:
	list <GameObject*> stage; //lista de objetos del estados
	SDLApp* app; //puntero a SDLApp
public:
	virtual void render() { for (GameObject* it : stage) { it->render(); } }; //manda a los objetos del estado render
	virtual void update() { for (GameObject* it : stage) { it->update(); } }; //manda a los objetos del estado update
	virtual void handleEvent(SDL_Event &e);
	GameState();
	~GameState() { for (GameObject* it : stage) { delete it; } }; //delete de los objetos
	GameState(SDLApp* app) : app(app) {}
};

