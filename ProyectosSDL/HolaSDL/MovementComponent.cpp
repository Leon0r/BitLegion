#include "MovementComponent.h"
#include "SDLApp.h"

//actualizamos la logica del personaje
void MovementComponent::update(GameObject* o, Uint32 time)
{
	Vector2D position = o->getPosition();
	Vector2D velocity = o->getVelocity();

	position = position + velocity;//actualizamos posicion en funcion de la velocidad
	double x = position.getX();
	double y = position.getY();

	//controlamos que el personaje no salga de la pantalla
	windowBounces(o, x, y, velocity);

	position.setX(x);
	position.setY(y);

	o->setPosition(position);
	o->setVelocity(velocity);
}

//controla que el personaje no salga de la pantalla
void MovementComponent::windowBounces(GameObject* o, double& x, double& y, Vector2D& velocity) {
	if (y <= 0) {
		y = 0;
		velocity.setY(0);
	}
	if (y + o->getHeight() >= o->getGame()->getWindowHeight()) {
		y = o->getGame()->getWindowHeight() - o->getHeight();
		velocity.setY(0);
	}

	if (x <= 0) {
		x = 0;
		velocity.setX(0);
	}

	if (x + o->getWidth() >= o->getGame()->getWindowWidth()) {
		x = o->getGame()->getWindowWidth() - o->getWidth();
		velocity.setX(0);
	}
}
