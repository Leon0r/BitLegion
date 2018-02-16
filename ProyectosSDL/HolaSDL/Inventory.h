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
	const double espaciado = 87;
	const double numCas = 5;
	vector<Vector2D> matriz;
public:
	Inventory() {};
	Inventory(SDLApp* app, ObjectList* inventario);
	virtual ~Inventory() { txt = nullptr; stage.clear(); };
};

