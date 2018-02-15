#pragma once
#include <SDL.h>
#include "InputComponent.h"

class ComponenteClickeable:
	public InputComponent
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	bool handleInput(GameObject* o, const SDL_Event& event);
private: 
	
};

