#pragma once
#include "InputComponent.h"
class pressButtonAnimation :
	public InputComponent
{
public:
	pressButtonAnimation();
	virtual ~pressButtonAnimation();
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
};
