#pragma once
#include <SDL.h>
#include "GameObject.h"

class ComponenteClickeable
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	bool handleEvent(GameObject* o, const SDL_Event& event);
private: 
	
};

