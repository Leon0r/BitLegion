#pragma once
#include <SDL.h>
#include "InputComponent.h"

class ComponenteClickeable:
	public InputComponent
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	void handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {};
	bool handleInput(GameObject* o, const SDL_Event& event);//Quitar Void y cambiar por bool
private: 
	
};

