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
public:
	Inventory() {};
	virtual ~Inventory() { txt = nullptr; stage.clear(); };

	//Se le pasa un puntero de la lista de objetos para que seamos capaces de modificarla desde aquí (por ahora se crea la textura), se pushean todos los elementos de la lista en stage
	Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) { txt = new Texture();  
			txt->loadFromImg(app->getRenderer(), "..//images/Alena.png"); inventario->addItem(txt, "a", "kk"); inventario->pushObjects(stage); };
};

