#include "MouseDirection.h"

void MouseDirection::setDirection(GameObject* o, Vector2D destiny) {
	pair <double, double> posJugador(o->getPosition().getX(), o->getPosition().getY()); //el vector2D no tiene operador "==" o "!="
	pair <double, double> posDestino(destiny.getX(), destiny.getY());
	if (posJugador != posDestino) {
		double modX = (o->getPosition().getX() - destiny.getX());
		double modY = (o->getPosition().getY() - destiny.getY());

		double hipo = sqrt(pow(modX, 2) + pow(modY, 2)); //pitagoras

		double sen = modY / hipo; //sacamos el seno y el coseno del triangulo
		double cosen = modX / hipo;

		o->setVelocity(Vector2D(-(cosen * vel), -(sen * vel)));  //establecemos la dirección y velocidad
	}
}


void MouseDirection::handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN  && event.button.button == SDL_BUTTON_RIGHT) {
		SDL_Point p;
		p.x = event.button.x;
		p.y = event.button.y;
		setDirection(o, Vector2D(p.x, p.y));
	}
}