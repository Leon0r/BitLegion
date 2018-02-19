#pragma once
#include <SDL.h>
#include "GameComponent.h"

class ComponenteClickeable
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	bool handleEvent(GameObject* o, const SDL_Event& event);
};
