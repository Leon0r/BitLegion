#include "KeyboardComponent.h"

//miramos eventos de teclado
void KeyboardComponent::handleInput(GameObject* o, Uint32 time, const SDL_Event& event)
{
	Vector2D velocity = o->getVelocity();

	//si se ha pulsado una tecla el personaje se mueve en la direccion correspondiente
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right) {
			//velocity = velocity + Vector2D(vel_, 0);
			velocity = Vector2D(0.1, 0);
		}
	    if (event.key.keysym.sym == left) {
			//velocity = velocity + Vector2D(-vel_, 0);
			velocity = Vector2D(-0.1, 0);
		}
	}
	// Solo cambia la velocidad a (0,0) si se sueltan la dcha y la izq
	else if (event.type == SDL_KEYUP && (event.key.keysym.sym == right || event.key.keysym.sym == left)) {

		velocity = Vector2D(0, 0);
	}

	o->setVelocity(velocity);
}
