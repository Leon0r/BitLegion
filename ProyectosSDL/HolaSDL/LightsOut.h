#pragma once
#include "GameState.h"
#include "CasillaLight.h"
#include "Boton.h"
#include "PlayState.h"

class LightsOut :
	public GameState, public Observer
{
private:
	ImageRenderer botonRender;
	ImageRenderer hudRend;
	Entity* hudAux; //puntero auxiliar al hud
	vector<Entity> decorado;
	vector<AnimationRenderer*> anim; //se deletea cada uno en su destructora del gameObject
	Boton* botonReset;
	bool faded = false;
	const int numCas = 3;
	const double tamCas = 150;
	const Uint8 alphaMin = 25;
	vector<vector<CasillaLight*>> lights;
	const double espaciado = 120.5 - 20*(numCas - 1);
	const int posX = 320 - 5 * (numCas - 1);
	const pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	vector<vector<bool>> aux; //guarda la configuracion inicial para el reset
	bool puzzleHasStarted;
	void apagaLuces(const unsigned int n); //invierte luces aleatorias "n" veces, así se garantiza solución
	void updateAux(); //actualiza aux despues de apagar todas las luces
	void restartMatrix();
	static void resetPuzzle(GameState* state);
	void creaDecoracion();
	void fadeOut();
public:
	LightsOut() {};
	virtual ~LightsOut();
	LightsOut(SDLApp* app);
	bool win();
	virtual void receive(Mensaje* msg);
	virtual void render();
	virtual void handleEvent(SDL_Event &e);
	Uint8 alpha = 255;
};

