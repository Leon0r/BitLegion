#pragma once
#include <SDL.h>
#include "GameObject.h"

class ComponenteClickeable
	//:public InputComponent
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();

	//bool handleEvent(GameObject* o, const SDL_Event& event);

	//void handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {};
	bool handleInput(GameObject* o, const SDL_Event& event);//Obtiene el rect del GO
	bool handleInput(SDL_Rect* rect, const SDL_Event& event);//recive un rectangulo destino

private: 
	
};

