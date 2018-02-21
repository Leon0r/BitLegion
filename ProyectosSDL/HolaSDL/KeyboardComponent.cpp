#include "KeyboardComponent.h"

//miramos eventos de teclado
void KeyboardComponent::handleInput(GameObject* o, Uint32 time, const SDL_Event& event)
{
	Vector2D velocity = o->getVelocity();

	//si se ha pulsado una tecla el personaje se mueve en la direccion correspondiente
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right) {
			r = true;
			velocity.setX(vel_);
			//si a la vez pulsamos arriba o abajo nos movemos en esa direccion tambien
			if (d)velocity.setY(vel_);
			else if(u)velocity.setY(-vel_);
			else velocity.setY(0);
		}
	    else if (event.key.keysym.sym == left) {
			l = true;
			velocity.setX(-vel_);
			//si a la vez pulsamos arriba o abajo nos movemos en esa direccion tambien
			if (d)velocity.setY(vel_);
			else if (u)velocity.setY(-vel_);
			else velocity.setY(0);
		}
		if (event.key.keysym.sym == up) {
			u = true;
			velocity.setY(-vel_);
			//si a la vez pulsamos izquierda o derecha nos movemos en esa direccion tambien
			if (r)velocity.setX(vel_);
			else if(l)velocity.setX(-vel_);
			else velocity.setX(0);
		}
		else if (event.key.keysym.sym == down) {
			d = true;
			velocity.setY(vel_);
			//si a la vez pulsamos izquierda o derecha nos movemos en esa direccion tambien
			if (r)velocity.setX(vel_);
			else if (l)velocity.setX(-vel_);
			else velocity.setX(0);
		}
	}

	// Solo cambia la velocidad a (0,0) si se sueltan la dcha y la izq no esta pulsada, etc.
	else if (event.type == SDL_KEYUP){
		if (event.key.keysym.sym == right) {
			r = false;
			if(!l)velocity.setX(0);
			else velocity.setX(-vel_);
		}
		else if (event.key.keysym.sym == left) {
			l = false;
			if(!r)velocity.setX(0);
			else velocity.setX(vel_);
		}
		if (event.key.keysym.sym == up) {
			u = false;
			if(!d)velocity.setY(0);
			else velocity.setY(vel_);
		}
		else if (event.key.keysym.sym == down) {
			d = false;
			if(!u)velocity.setY(0);
			else velocity.setY(-vel_);
		}
	}
	o->setVelocity(velocity);
}
