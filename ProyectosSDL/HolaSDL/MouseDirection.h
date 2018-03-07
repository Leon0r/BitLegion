#pragma once
#include "InputComponent.h"
#include "Entity.h"
class MouseDirection :
	public InputComponent
{
private:
	double vel;
	SDL_Point p; //punto donde el jugador ha clickado
public:
	MouseDirection() {};
	~MouseDirection() {};
	MouseDirection(double vel) : vel(vel) {};
	//miramos eventos de teclado
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
	void setDirection(GameObject* o, Vector2D destiny);
	void stopMovement(GameObject* o, Vector2D destiny);
};

