#pragma once
#include "GameState.h"
#include "CasillaInventario.h"
#include "ComponenteClickeable.h"
#include "ObjectList.h"

const unsigned int tamanyoFuente = 35;
const SDL_Color colorFuente = { 255, 255, 255, 1 };

class Inventory :
	public GameState
{
private:
	GameState* previousState;
	Texture fuente;
	Font* f;
	bool bswap = false;
	CasillaInventario* selected;
	Entity* copia;
	RenderComponent* imagen;
	RenderComponent* imagenMarca;
	RenderComponent* selectedTexture;
	Entity* inventarioHud = new Entity(app);
	Entity* marca = new Entity(app);
	const double espaciado = 87;
	int coefRed;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	const int numCas = 5;
	vector<Vector2D> matriz, matrizS;
	static void usar(GameState* state); 
										 //ya funciona, se puede usar un cast para un metodo del inventario (usar, swap, por ejemplo)
	static void swap(GameState* state);
public:
	Inventory() {};
	Inventory(SDLApp* game, ObjectList* inventario, GameState* previousState, int coefRed, vector<Vector2D> matS);
	virtual ~Inventory() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event);
	virtual void render();
	void muestraDescripcion();
	CasillaInventario* getLastClicked() { return selected; };
	void destroy();
	ObjectList* inventario;
	GameState* getPreviousState() { return previousState; };
};

