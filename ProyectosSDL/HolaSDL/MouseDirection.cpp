#include "MouseDirection.h"
#include "MainCharacter.h"
#include "MouseMovement.h"

//se establece la direccion que el objeto o debera seguir para llegar a destino
void MouseDirection::setDirection(GameObject* o, Vector2D destiny) {
		/*double modX = (o->getPosition().getX() - destiny.getX());
		double modY = (o->getPosition().getY() + o->getHeight() - destiny.getY());
		double hipo = sqrt(pow(modX, 2) + pow(modY, 2)); //pitagoras

		double sen = modY / hipo; //sacamos el seno y el coseno del triangulo
		double cosen = modX / hipo;

		o->setVelocity(Vector2D(-(cosen * vel), -(sen * vel)));  //establecemos la dirección y velocidad*/
}

//eventos de mouse
void MouseDirection::handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {
	//si se pulsa el raton registramos su posicion
	/*if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		p.x = event.button.x;
		p.y = event.button.y;
	}
	//si se suelta elegimos la direccion del jugador para llegar a esa posicion y actualizamos la posicion destino del componente mouseMov
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {
		setDirection(o, Vector2D(p.x, p.y));
		static_cast<MouseMovement*>(mouseMov)->setDestiny(p.x, p.y);
	}*/
}
