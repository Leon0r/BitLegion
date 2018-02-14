#pragma once
#include "InputComponent.h"
class KeyboardComponent :
	public InputComponent
{
public:
	KeyboardComponent(GameObject* obj, SDL_Keycode right, SDL_Keycode left);
	~KeyboardComponent();

	void handleEvent(Uint32 time, const SDL_Event& event);

protected:
	SDL_Keycode right;
	SDL_Keycode left;
	GameObject* obj;
};

