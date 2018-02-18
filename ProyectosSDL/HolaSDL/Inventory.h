#pragma once
#include "GameState.h"
#include "CasillaInventario.h"
#include "ComponenteClickeable.h"
#include "ObjectList.h"

class Inventory :
	public GameState
{
private:
	ObjectList* inventario;
	Texture* txt;
	Texture* txt2;
	Texture* txt3;
	Texture* txt4;
	CasillaInventario* copia = new CasillaInventario();
	RenderComponent* imagen;
	GameComponent* inventarioHud = new GameComponent(app);
	GameComponent* marca = new GameComponent(app);
	const double espaciado = 87;
	const int numCas = 5;
	vector<Vector2D> matriz;
	static void usar(GameState* state) { /*static_cast<Inventory*>(state)->punteroStateAnterior->FuncionTag(static_cast<Inventory*>(state)->anteriorClickado->tag):
										 /*app->popState();
										 */std::cout << "usandooo" << static_cast<Inventory*>(state)->getLastClicked()->getDescription();}; //ya funciona, se puede usar un cast para un metodo del inventario (usar, swap, por ejemplo)
public:
	Inventory() {};
	Inventory(SDLApp* app, ObjectList* inventario);
	virtual ~Inventory() { txt = nullptr; stage.clear(); };
	virtual void handleEvent(SDL_Event& event);
	void muestraDescripcion(CasillaInventario* aux);
	CasillaInventario* getLastClicked() { return copia; };
};

