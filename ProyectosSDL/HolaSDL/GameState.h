#pragma once
#include "GameObject.h"
#include "Font.h"
#include "Texture.h"
#include <list>

const int FRAME_RATE = 25; // A menor tiempo de espera entre frames, mayor la velocidad del bucle

class Entity;
class GameState
{
private:
	bool listhasChanged = false;

protected:
	uint32_t startTime, frameTime; // Control del tiempo de repeticion del bucle

	list <GameObject*> stage; //lista de objetos del estados
	list<GameObject*>::iterator it;
	SDLApp* app; //puntero a SDLApp
public:
	virtual void render(); //manda a los objetos del estado render, el 0 es por el tiempo que no sé porq lo tenemos
	virtual void update(); //manda a los objetos del estado update
	virtual void handleEvent(SDL_Event &e);
	void addEntity(GameObject* entity){ stage.push_back(entity); }
	GameState();
	virtual ~GameState() { for (GameObject* it : stage) { delete it; } }; //delete de los objetos
	GameState(SDLApp* app) : app(app) {}
	void deleteElement(GameObject* o);
	list <GameObject*>* getStage() {return &stage;}
	void changeList() { listhasChanged = true; }
};

