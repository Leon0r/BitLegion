#pragma once
#include "InputComponent.h"
class OverlapCursorAnimation :
	public InputComponent
{
public:
	OverlapCursorAnimation();
	virtual ~OverlapCursorAnimation();
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
};

