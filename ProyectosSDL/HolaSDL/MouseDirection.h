#pragma once
#include "InputComponent.h"
#include "Entity.h"

//se encarga de elegir la direccion del jugador cuando esta con el raton
class MouseDirection : public InputComponent
{
private:
	double vel;
	SDL_Point p; //punto donde el jugador ha clickado
	PhysicsComponent* mouseMov;//puntero al componente que mueve por raton para actualizar su punto destino
public:
	MouseDirection() {};
	~MouseDirection() {};
	MouseDirection(double vel, PhysicsComponent* mouseM) : vel(vel), mouseMov(mouseM) {};
	//miramos eventos de teclado
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
	void setDirection(GameObject* o, Vector2D destiny);
};

