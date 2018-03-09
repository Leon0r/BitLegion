#pragma once
#include "MovementComponent.h"
#include "InputComponent.h"

//se encarga de mover al jugador cuando esta con el raton
class MouseMovement : public InputComponent, public MovementComponent
{
public:
	MouseMovement() {}
	MouseMovement(list<GameObject*>* colisiones, double vel) : MovementComponent(colisiones), vel(vel) {
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
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
	void setDirection(GameObject* o, Vector2D destiny);
	bool playerInDestiny(GameObject* o, Vector2D destiny);
private:
	Vector2D destiny;
	double vel;
	SDL_Point p;
	int grid[9][10] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	int auxX = 142;
	int auxY = 90;
};

