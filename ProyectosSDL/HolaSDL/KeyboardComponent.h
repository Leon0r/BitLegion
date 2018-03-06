#pragma once
#include "InputComponent.h"
#include "Inventory.h"
#include "PlayState.h"
#include <stack>

using namespace std;

//componente de teclado, es un inputComponent
class KeyboardComponent : public InputComponent {
public:
	//establecemos velocidad y teclas de direccion
	KeyboardComponent(double v, SDL_Keycode right, SDL_Keycode left, SDL_Keycode up, SDL_Keycode down, SDL_Keycode inv) :
		vel_(v), right(right), left(left), up(up), down(down), inventory(inv) {}
	~KeyboardComponent() {}

	//miramos eventos de teclado
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);

private:
	double vel_;//velocidad y teclas de direccion
	SDL_Keycode right;
	SDL_Keycode left;
	SDL_Keycode up;
	SDL_Keycode down;
	SDL_Keycode inventory;
	stack<SDL_Keycode> Xaxis;//pila de teclas del eje x
	stack<SDL_Keycode> Yaxis;//pila de teclas del eje y
	//flags para saber si has pulsado las teclas
	bool r = false, l = false, u = false, d = false;
};

