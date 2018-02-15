#pragma once
#include <SDL.h>
#include "InputComponent.h"

class ComponenteClickeable:
	public InputComponent
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
	bool handleEvent(GameObject* o, const SDL_Event& event);
};
