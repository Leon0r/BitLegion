#pragma once
#include <SDL.h>

class ComponenteClickeable
{
public:
	ComponenteClickeable(SDL_Rect _rect);
	~ComponenteClickeable();
	bool handleEvent(SDL_Event e);
private: 
	SDL_Rect rect;
};

