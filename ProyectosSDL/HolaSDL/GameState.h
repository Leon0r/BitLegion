#pragma once
#include "GameObject.h"
#include "SDLApp.h"
#include <list>
#include <string>
#include "Texture.h"
#include "ImageRenderer.h"

class GameState
{
protected:
	list <GameObject*> stage; //lista de objetos del estados
	SDLApp* app; //puntero a SDLApp
public:
	virtual void render() { for (GameObject* it : stage) { it->render(0); } }; //manda a los objetos del estado render, el 0 es por el tiempo que no s� porq lo tenemos
	virtual void update() { for (GameObject* it : stage) { it->update(0); } }; //manda a los objetos del estado update
	virtual void handleEvent(SDL_Event &e);
	GameState();
	virtual ~GameState() { for (GameObject* it : stage) { delete it; } }; //delete de los objetos
	GameState(SDLApp* app) : app(app) {}
};

