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
	const int numCas = 3; //leerlo de alguna parte (json)
	vector<vector<CasillaLight*>> lights;
	const int espaciado = 85.0;
	const pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	vector<vector<bool>> aux; //guarda la configuracion inicial para el reset
	bool puzzleHasStarted;
	void apagaLuces(const unsigned int n); //invierte luces aleatorias "n" veces, así se garantiza solución
	void updateAux(); //actualiza aux despues de apagar todas las luces
	Boton* botonReset;
	void restartMatrix();
	static void resetPuzzle(GameState* state);
public:
	LightsOut() {};
	virtual ~LightsOut();
	LightsOut(SDLApp* app);
	bool win();
	virtual void receive(Mensaje* msg);
	//virtual void update(); animacion maybe (?)
};

