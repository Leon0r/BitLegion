#pragma once
#include "GameState.h"
#include "CasillaPuzzle1.h"
#include "SDLApp.h"

const unsigned int tamanyoFuente = 35;
const SDL_Color colorFuente = { 255, 255, 255, 1 };

class Puzzle1State :
	public GameState
{
private:
	GameState* previousState;
	Texture fuente;
	Font* f;
	bool bswap = false;
	Entity* copia;
	RenderComponent* imagen;
	RenderComponent* imagenMarca;
	RenderComponent* selectedTexture;
	Entity* puzzleHud = new Entity(app);
	Entity* marca = new Entity(app);
	const double espaciado = 87;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	const int numCas = 5;
	vector<Vector2D> matriz;
	static void usar();
	vector<vector<CasillaPuzzle1*>> matriz;
public:
	Puzzle1State() {};
	Puzzle1State(SDLApp* game,  GameState* previousState);
	virtual ~Puzzle1State() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event);
	virtual void render();
	CasillaPuzzle1* getLastClicked() {};
	void destroy();
	GameState* getPreviousState() { return previousState; };
};