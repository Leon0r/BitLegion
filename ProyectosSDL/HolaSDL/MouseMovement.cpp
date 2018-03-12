#include "MouseMovement.h"
#include "MainCharacter.h"
#include "AStar.h"




MouseMovement::MouseMovement(list<GameObject*>* colisiones, double vel, MainCharacter* o) : MovementComponent(colisiones), vel(vel), o(o) {
	destiny.setX(0);
	destiny.setY(0);
	nek = new AStar(this);
	nek->defineCosas(o);
}

//actualizamos la logica del personaje
void MouseMovement::update(GameObject* o, Uint32 time) {
	if (!stackerino.empty()) {//si hay destinos pendientes
		if (playerInDestiny(o, destiny)) {//si el jugador ha llegado al destino actual
			stackerino.pop();
			if (!stackerino.empty()) {//establecemos el siguiente destino de la cola
				setDestiny(stackerino.front().first, stackerino.front().second);
				setDirection(o, destiny);//le mandamos hacia el
			}
		}
		else {
			//si esta viajando a un destino, update del movimiento normal
			Vector2D position = o->getPosition();
			Vector2D velocity = o->getVelocity();

			position = position + velocity;//actualizamos posicion en funcion de la velocidad

			o->setPosition(position);
			o->setVelocity(velocity);
		}
	}
	stopMovement(o, destiny);//si llega a la posicion destino se para
}

//miramos si ha llegado a la posicion destino
void MouseMovement::stopMovement(GameObject* o, Vector2D destiny) {
	if (playerInDestiny(o, destiny)) {
		o->setVelocity(Vector2D(0, 0));
	}
}

//se establece la direccion que el objeto o debera seguir para llegar a destino
void MouseMovement::setDirection(GameObject* o, Vector2D destiny) {
	double modX = (o->getPosition().getX() - destiny.getX());
	double modY = (o->getPosition().getY() + o->getHeight() - destiny.getY());
	double hipo = sqrt(pow(modX, 2) + pow(modY, 2)); //pitagoras

	double sen = modY / hipo; //sacamos el seno y el coseno del triangulo
	double cosen = modX / hipo;

	o->setVelocity(Vector2D(-(cosen * vel), -(sen * vel)));  //establecemos la dirección y velocidad
}

//eventos de mouse
void MouseMovement::handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {

	generaMatriz(o); //problem here

	//si se pulsa el raton registramos su posicion
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		p.x = event.button.x;
		p.y = event.button.y;
	}

	//si se suelta elegimos la direccion del jugador para llegar a esa posicion y actualizamos la posicion destino del componente mouseMov
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {

		while (!stackerino.empty()) { stackerino.pop(); }//eliminamos el path anterior

		//aestrella rellena una cola de destinos para llegar al final
		nek->aStarSearch(grid2, pair<double, double>(o->getPosition().getX() / auxX, (
			o->getPosition().getY() + o->getHeight()) / auxY), pair<double, double>(p.x / auxX, p.y / auxY));

		//si ha encontrado destinos
		if (!stackerino.empty()) {
			setDestiny(stackerino.front().first, stackerino.front().second); //establecemos el primero
			setDirection(o, destiny);//le mandamos hacia el
		}
	}
}

bool MouseMovement::playerInDestiny(GameObject* o, Vector2D destiny) {
	SDL_Rect rectDestino = { destiny.getX() - o->getWidth() / 4, destiny.getY() - o->getWidth() / 6, o->getWidth() / 2 , o->getWidth() / 2 };
	SDL_Point q = { o->getPosition().getX() + o->getWidth() / 4, o->getPosition().getY() + o->getHeight() };
	return (SDL_PointInRect(&q, &rectDestino));
}

void MouseMovement::generaMatriz(GameObject* o) {
	int x, y;
	x = 20;
	y = 0;
	for (int i = 720/2 + 18/2; i < 720; i+=18) {
		y = 0;
		for (int j = 32 / 2; j < 1280; j += 32) {
			list<GameObject*>::iterator it = collisions->begin();
			bool colisionado = false;
			while (it != collisions->end() && !colisionado) {
				SDL_Rect rect = { (*it)->getPosition().getX(), (*it)->getPosition().getY(), (*it)->getWidth(), (*it)->getHeight() };
				SDL_Point pMedio = { j, i };

				if (SDL_PointInRect(&pMedio, &rect)) {
					colisionado = true;
					grid2[y][x] = 0;
				}
				else grid2[y][x] = 1;
				it++;
			}
			y++;
		}
		x++;
	}
}
