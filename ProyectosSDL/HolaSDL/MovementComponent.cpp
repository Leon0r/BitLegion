#include "MovementComponent.h"
#include "SDLApp.h"

//actualizamos la logica del personaje
void MovementComponent::update(GameObject* o, Uint32 time) {
	Vector2D position = o->getPosition();
	Vector2D velocity = o->getVelocity();
	
	position = position + velocity;//actualizamos posicion en funcion de la velocidad
	double x = position.getX();
	double y = position.getY();

	windowBounces(o, x, y, velocity);//limites de la pantalla
	collideObjects(o, x, y, velocity);//colisiones con objetos de la escena

	position.setX(x);
	position.setY(y);
	o->setPosition(position);
	o->setVelocity(velocity);
}

//controla que el personaje no salga de la pantalla
void MovementComponent::windowBounces(GameObject* o, double& x, double& y, Vector2D& velocity) {
	if (y + o->getHeight()*2 / 3 <= /*o->getGame()->getWindowHeight() / 2*/ 0) {
		y = /*o->getGame()->getWindowHeight() / 2 - o->getHeight()*2 / 3*/ 0;
		velocity.setY(0);
	}
	else if (y + o->getHeight() >= o->getGame()->getWindowHeight()) {
		y = o->getGame()->getWindowHeight() - o->getHeight();
		velocity.setY(0);
	}
	if (x <= 0) {
		x = 0;
		velocity.setX(0);
	}
	else if (x + o->getWidth() >= o->getGame()->getWindowWidth()) {
		x = o->getGame()->getWindowWidth() - o->getWidth();
		velocity.setX(0);
	}
}

//controla que el personaje no colisione con ningun objeto
void MovementComponent::collideObjects(GameObject* o, double& x, double& y, Vector2D& velocity)
{
	it = collisions->begin();
	while (it != collisions->end() && !Collisions::collides(o, *it)) { ++it; }

	//si hemos colisionado con algun objeto de la escena
	if (it != collisions->end()) {
		//si hemos colisionado por los lados
		if (o->getPosition().getX()<=(*it)->getPosition().getX()-o->getWidth() ||
			o->getPosition().getX() >= (*it)->getPosition().getX() + (*it)->getWidth()){
			x -= velocity.getX();//establecemos la posicion anterior
			velocity.setX(0);//paramos en x
		}
		//si hemos colisionado por arriba o abajo
		else if (o->getPosition().getY() <= (*it)->getPosition().getY() - o->getHeight()/4 ||
			o->getPosition().getY() + o->getHeight() >= (*it)->getPosition().getY()) {
			y -= velocity.getY();//establecemos la posicion anterior
			velocity.setY(0);//paramos en y
		}
	}
}
