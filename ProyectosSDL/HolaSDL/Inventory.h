#pragma once
#include "checkML.h"
#include "GameState.h"
#include "CasillaInventario.h"
#include "ObjectList.h"
#include "ShortCut.h"
#include "Boton.h"
#include "sdl_includes.h"
#include "pressButtonAnimation.h"

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
	Entity* copia = nullptr;
	RenderComponent* imagen;
	RenderComponent* imagenMarca;
	RenderComponent* selectedTexture;
	Boton* useButton;
	Boton* swapButton;
	Entity* inventarioHud = new Entity(app);
	Entity* marca = new Entity(app);
	ShortCut* SC;
	pressButtonAnimation pb, pb1;
	const double espaciado = 87;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0 , app->getWindowHeight() / 600.0 };
	const int numCas = 5;
	vector<Vector2D> matriz;
	SDL_Rect rectF = RECT(0, 0, app->getWindowWidth(), app->getWindowHeight());
	void usar(Inventory* state); 
										 //ya funciona, se puede usar un cast para un metodo del inventario (usar, swap, por ejemplo)
	void swap(Inventory* state);
	function<void()> usFunc_;
	function<void()> swFunct_;
public:
	Inventory() {};
	Inventory(SDLApp* game, ObjectList* inventario, GameState* previousState, ShortCut* shortcut);
	virtual ~Inventory() { destroy(); stage.clear(); };
	virtual void handleEvent(SDL_Event& event);
	virtual void render();
	void muestraDescripcion();
	CasillaInventario* getLastClicked() { return selected; };
	void destroy();
	ObjectList* inventario;
	GameState* getPreviousState() { return previousState; };
};

