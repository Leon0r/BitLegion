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
	Texture fuente;
	Font* f;
	Entity* copia;
	RenderComponent* imagenMarca;
	RenderComponent* selectedTexture;
	const int espaciado = 85.0;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	const double topD = relacion.first*(espaciado*4 + 137 + espaciado/2), topI = relacion.first*(137-espaciado/2), topA = relacion.second*(112 - espaciado / 2), topAB = relacion.second*(espaciado*4 + 112 + espaciado / 2);
	double auxI, auxD, auxA, auxAB;
	bool mover = false;
	int currentFil, currentCol;
	const int numCas = 5;
	vector<vector<CasillaPuzzle1*>> matriz;
	static void usar(GameState* state, int fil, int col);
	vector<Boton*> botones;
public:
	Puzzle1State() {};
	Puzzle1State(SDLApp* game,  GameState* previousState);
	virtual ~Puzzle1State() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event) { GameState::handleEvent(event); }
	virtual void render() { GameState::render();}
	virtual void update();
	void tresUnidos();
	void mueveMatriz();
	void reestableFC(int f, int c){ //by gonzalo
		if (f != -1) {
			for (int i = 0; i < numCas-1; i++)
				swap(matriz[f][0], matriz[f][i+1]);
		}
		else for (int i = numCas-1; i > 0; i--)
			swap(matriz[4][c], matriz[i - 1][c]);
	}
	void destroy();
	GameState* getPreviousState() { return previousState; };
};