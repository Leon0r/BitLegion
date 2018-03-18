#pragma once
#include "GameState.h"
#include "CasillaPuzzle1.h"
#include "SDLApp.h"
#include "MovementComponent.h"
#include "ImageRenderer.h"
#include "AnimationRenderer.h"

/*const unsigned int tamanyoFuente = 35;
const SDL_Color colorFuente = { 255, 255, 255, 1 };*/

class Puzzle1State :
	public GameState
{
private:
	GameState* previousState;
	Texture fuente;
	Font* f;
	Entity* copia;
	RenderComponent* imagen;
	RenderComponent* imagenMarca;
	RenderComponent* selectedTexture;
	Entity* puzzleHud = new Entity(app);
	Entity* marca = new Entity(app);
	const double espaciado = 87.0;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	double topD = relacion.first*(485.0 + 43.5), topI = relacion.first*93.5;
	double auxI, auxD;
	const int numCas = 5;
	vector<vector<CasillaPuzzle1*>> matriz;
	static void usar(GameState* state, int fil, int col);
public:
	Puzzle1State() {};
	Puzzle1State(SDLApp* game,  GameState* previousState);
	virtual ~Puzzle1State() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event) { GameState::handleEvent(event); }
	virtual void render() { GameState::render();}
	virtual void update() {
		GameState::update();
		if (auxD > auxI) {
			for (int i = 0; i < numCas; i++) {
				matriz[0][i]->setPosition(matriz[0][i]->getPosition() + matriz[0][i]->getVelocity());
				if (matriz[0][i]->getPosition().getX() > topD) matriz[0][i]->setPosition(Vector2D(topI, relacion.second * 112));

			}
			auxI = matriz[0][0]->getPosition().getX();
		}
	}
	CasillaPuzzle1* getLastClicked() {};
	void tresUnidos() {};
	void mueveMatriz() {};
	void destroy();
	GameState* getPreviousState() { return previousState; };
};