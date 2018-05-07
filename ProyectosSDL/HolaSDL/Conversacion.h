#pragma once
#include "NodoDialogo.h"
#include "GameObject.h"
#include "Font.h"
#include "Texture.h"

const unsigned int tamanyoFuenteConv = 40;
const SDL_Color colorFuenteConv = { 0, 169, 0, 1 }; //38c81f // es el verde fosforito en hexadecimal pero no se ve bien (creo que se escribe por debajo)

class Conversacion : public GameObject
{
public:
	Conversacion(SDLApp* game);
	virtual ~Conversacion();
	void escribir();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual Texture* getTexture(Uint16 pos) const{
		return nullptr;
	}

	void ConversacionDePrueba();
	bool loadConversation(string fileName);

	virtual void saveToJson(json& j) {};

private:
	vector<NodoDialogo> dialogo;
	int nodoActual = 0;

	const int GUIx = 0;
	const int GUIy = 360;
	const int GUIw = 1242;
	const int GUIh = 355;

	const int x = 200;
	const int y = 520;			//MIRAR DONDE QUEDA BIEN
	const int w = 1200;
	const int h = 168;			//MIRAR DONDE QUEDA BIEN, HACERLO EN FUNCION DE TAMAÑO DE PANTALLA EN VEZ DE A LO BRUTO

	const int retratoX = 15;
	const int retratoY = 376;
	const int retratoW = 125;
	const int retratoH = 125;

	SDL_Rect clip = { 0,0,130,130 };


	int grupoOps = 0;


	Mensaje* msg = nullptr;


	Font* f;
};

