#include "KeyboardComponent.h"


//miramos eventos de teclado
void KeyboardComponent::handleInput(GameObject* o, Uint32 time, const SDL_Event& event)
{
	if (list == nullptr) {
		list = new ObjectList(o->getGame());
	}
	Vector2D velocity = o->getVelocity();

	//si se ha pulsado una tecla el personaje se mueve en la direccion correspondiente
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right) {
			r = true;
			velocity.setX(vel_);
		}
	    else if (event.key.keysym.sym == left) {
			l = true;
			velocity.setX(-vel_);
		}
		if (event.key.keysym.sym == up) {
			u = true;
			velocity.setY(-vel_);
		}
		else if (event.key.keysym.sym == down) {
			d = true;
			velocity.setY(vel_);
		}
		if (event.key.keysym.sym == inventory) {
			o->getGame()->getStateMachine()->pushState(new Inventory(o->getGame(), list));

		}
		else if (event.key.keysym.sym == SDLK_a) {
			Texture* txt = new Texture(o->getGame()->getRenderer(), "..//images/Alena.png");
			list->addItem(txt, "kk", "holis");
			list->addItem(txt, "adsa", "dfghdfgdsf");
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
