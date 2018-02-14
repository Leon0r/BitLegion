#pragma once
#include "InputComponent.h"
class KeyboardComponent :
	public InputComponent
{
public:
	KeyboardComponent(SDL_Keycode right, SDL_Keycode left);
	~KeyboardComponent();

	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);

protected:
	SDL_Keycode right;
	SDL_Keycode left;
};

