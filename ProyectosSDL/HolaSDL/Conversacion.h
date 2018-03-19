#pragma once
#include "NodoDialogo.h"
#include "GameObject.h"
#include "Font.h"
#include "Texture.h"


const unsigned int tamanyoFuenteConv = 100;
const SDL_Color colorFuenteConv = { 255, 255, 255, 1 };

class Conversacion : public GameObject
{
public:
	Conversacion(SDLApp* game);
	~Conversacion();
	void escribir();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual Texture* getTexture(Uint16 pos) const{
		return nullptr;
	}

	void ConversacionDePrueba();

private:
	vector<NodoDialogo*> dialogo;
	int nodoActual;
	const int x = 40;
	const int y = 540;			//MIRAR DONDE QUEDA BIEN
	const int w = 1200;
	const int h = 168;			//MIRAR DONDE QUEDA BIEN, HACERLO EN FUNCION DE TAMA�O DE PANTALLA EN VEZ DE A LO BRUTO

	int grupoOps = 0;

	bool enconversacion = true;

	Font* f;
};

