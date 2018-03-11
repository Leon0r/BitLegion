#pragma once
#include "MovementComponent.h"
#include "InputComponent.h"
#include <queue>

//se encarga de mover al jugador cuando esta con el raton
class MouseMovement : public InputComponent, public MovementComponent
{
private:
	int grid2[10][10] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	Vector2D destiny;
	double vel;
	SDL_Point p;
	int auxX = 128;
	int auxY = 72;
public:
	queue<pair<int, int>> stackerino;
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
	void generaMatriz(GameObject* o);
};

