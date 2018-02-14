#include "KeyboardComponent.h"



KeyboardComponent::KeyboardComponent(GameObject* obj, SDL_Keycode right, SDL_Keycode left)
	: obj(obj), right(right), left(left)
{
}


KeyboardComponent::~KeyboardComponent()
{
}

void KeyboardComponent::handleEvent(Uint32 time, const SDL_Event & event)
{
	Vector2D velocity = obj->getVelocity();

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right) {
			velocity.setX(2);
		}
		else if (event.key.keysym.sym == left) {
			velocity.setX(-2);
		}
	}

	obj->setVelocity(velocity);
}
