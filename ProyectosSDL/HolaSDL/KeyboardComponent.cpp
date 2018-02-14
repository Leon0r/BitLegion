#include "KeyboardComponent.h"



KeyboardComponent::KeyboardComponent(SDL_Keycode right, SDL_Keycode left)
	: right(right), left(left)
{
}


KeyboardComponent::~KeyboardComponent()
{
}

void KeyboardComponent::handleInput(GameObject* o, Uint32 time, const SDL_Event& event)
{
	Vector2D velocity = o->getVelocity();

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right) {
			velocity.setX(-5);
		}
		else if (event.key.keysym.sym == left) {
			velocity.setX(5);
		}
	}

	o->setVelocity(velocity);
}
