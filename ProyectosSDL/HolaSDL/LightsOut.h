#pragma once
#include "GameState.h"
#include "CasillaLight.h"

class LightsOut :
	public GameState, public Observer
{
private:
	const int numCas = 3; //leerlo de alguna parte (json)
	vector<vector<CasillaLight*>> lights;
	const int espaciado = 85.0;
	const pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
public:
	LightsOut() {};
	virtual ~LightsOut();
	LightsOut(SDLApp* app);
	bool win();
	virtual void receive(Mensaje* msg);
	//virtual void update(); animacion maybe (?)
};

