#pragma once
#include "MovementComponent.h"
#include "InputComponent.h"
#include <queue>

//se encarga de mover al jugador cuando esta con el raton
class AStar;
class MainCharacter;
const int tamMatriz = 40;//numero de casillas que tendra la matriz en ancho y alto

class MouseMovement : public InputComponent, public MovementComponent
{
private:
	int grid2[tamMatriz][tamMatriz] = {0};//matriz de la escena, inicialmente con todo ceros
	Vector2D destiny;
	double vel;
	SDL_Point p, q;//punto destino (p) y destino anterior (q)
	int sceneWidth, sceneHeight;
	int auxX, auxY;//reescalado de la matriz
	AStar* nek;
	MainCharacter* o;
	bool solucionadorBugs();//soluciona bugs, de omento no esta activo
	bool idleRight = true;//determina hacia que lado estamos mirando cuando estamos parados
public:
	queue<pair<int, int>> stackerino;//cola de destinos intermedios para llegar al final
	MouseMovement() {}
	MouseMovement(list<GameObject*>* colisiones, double vel, MainCharacter* o);
	~MouseMovement() { delete nek; }

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
	void generaMatriz(GameObject* o);//inicializa a la matriz con los valores adecuados (0 colisionable, 1 vacio)
};
