#pragma once
#include <SDL.h>
#include "InputComponent.h"

class ComponenteClickeable
	//:public InputComponent
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	//void handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {};
	bool handleInput(GameObject* o, const SDL_Event& event);//Obtiene el rect del GO
	bool handleInput(SDL_Rect* rect, const SDL_Event& event);//recive un rectangulo destino

private: 
	
};

