#pragma once
#include "GameState.h"
#include "CasillaPuzzle1.h"
#include "SDLApp.h"
#include "MovementComponent.h"
#include "ImageRenderer.h"
#include "AnimationRenderer.h"
#include "Boton.h"

class Puzzle1State :
	public GameState
{
private:
	GameState* previousState;
	vector<vector<CasillaPuzzle1*>> matriz;
	vector<Boton*> botones;
	RenderComponent* imagenMarca;
	const int espaciado = 85.0;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	const double topD = relacion.first*(espaciado*4 + 137 + espaciado/2), topI = relacion.first*(137-espaciado/2), topA = relacion.second*(112 - espaciado / 2), topAB = relacion.second*(espaciado*4 + 112 + espaciado / 2);
	double auxI, auxD, auxA, auxAB;
	bool mover = false;
	int currentFil, currentCol;
	const int numCas = 5;
	int numRestantes = 0;

	static void usar(GameState* state, int fil, int col);
	void checkLine(int line, bool Vert);
public:
	Puzzle1State() {};
	Puzzle1State(SDLApp* game,  GameState* previousState);
	virtual ~Puzzle1State() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event) { 
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_p) {
				app->getStateMachine()->popState();
			}
		}
		else GameState::handleEvent(event);
	}
	virtual void render() { 
		if (previousState != nullptr) previousState->render();
		GameState::render(); 
	}
	virtual void update();
	void tresUnidos();
	void mueveMatriz();
	void reestableFC(int f, int c){ //by gonzalo
		if (f != -1) {
			for (int i = 0; i < numCas - 1; i++) swap(matriz[f][0], matriz[f][i + 1]);
			for (int i = 0; i < numCas; i++) matriz[f][i]->setPosition(Vector2D((int)topI + ((int)(relacion.first*espaciado) / 2) + (int)(i*espaciado*relacion.first), matriz[f][i]->getPosition().getY()));
		}
		else {
			for (int i = numCas - 1; i > 0; i--) swap(matriz[4][c], matriz[i - 1][c]);
			for (int i = 0; i < numCas; i++) {
				int j = (int)topAB - ((int)(relacion.second*espaciado) / 2) - (int)(i*espaciado*relacion.second);
				matriz[numCas-1-i][c]->setPosition(Vector2D(matriz[numCas-1-i][c]->getPosition().getX(), j));
			}
		}
	}
	void destroy();
	GameState* getPreviousState() { return previousState; };
};