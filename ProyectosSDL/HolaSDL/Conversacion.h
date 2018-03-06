#pragma once
#include "NodoDialogo.h"
#include "GameObject.h"
class Conversacion : public GameObject
{
public:
	Conversacion();
	~Conversacion();
	void escribir();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	vector<NodoDialogo> dialogo;
	int nodoActual;
	const int x = 40;
	const int y = 540;			//MIRAR DONDE QUEDA BIEN
};

