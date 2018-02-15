#pragma once
#include "InputComponent.h"

//componente de teclado, es un inputComponent
class KeyboardComponent : public InputComponent {
public:
	//establecemos velocidad y teclas de direccion
	KeyboardComponent(double v, SDL_Keycode right, SDL_Keycode left) : vel_(v), right(right), left(left) {}
	~KeyboardComponent() {}

	//miramos eventos de teclado
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);

private:
	double vel_;//velocidad y teclas de direccion
	SDL_Keycode right;
	SDL_Keycode left;
};

