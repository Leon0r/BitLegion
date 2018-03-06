#pragma once
#include "InputComponent.h"
class MouseDirection :
	public InputComponent
{
private:
	double vel;
public:
	MouseDirection() {};
	~MouseDirection() {};
	MouseDirection(double vel) : vel(vel) {};
	//miramos eventos de teclado
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
	void setDirection(GameObject* o, Vector2D destiny);
};

