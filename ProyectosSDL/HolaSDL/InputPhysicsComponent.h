#pragma once
#include "InputComponent.h"
#include "PhysicsComponent.h"

class InputPhysicsComponent:public InputComponent, public PhysicsComponent{
public:
	InputPhysicsComponent() {}
	~InputPhysicsComponent() {}
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event) = 0;
	virtual void update(GameObject* o, Uint32 time) = 0;
};

