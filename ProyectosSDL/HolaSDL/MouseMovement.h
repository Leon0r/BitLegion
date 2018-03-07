#pragma once
#include "MovementComponent.h"

//se encarga de mover al jugador cuando esta con el raton
class MouseMovement : public MovementComponent
{
public:
	MouseMovement() {}
	MouseMovement(list<GameObject*>* colisiones) : MovementComponent(colisiones) {
		destiny.setX(0);
		destiny.setY(0);
	}
	~MouseMovement() {}

	//actualizamos la logica del personaje
	virtual void update(GameObject* o, Uint32 time);
	//miramos si ha llegado a la posicion destino
	void stopMovement(GameObject* o, Vector2D destiny);
	//actualizamos la posicion destino a la que quiere ir
	void setDestiny(double x, double y) {
		destiny.setX(x);
		destiny.setY(y);
	}
private:
	Vector2D destiny;
};

