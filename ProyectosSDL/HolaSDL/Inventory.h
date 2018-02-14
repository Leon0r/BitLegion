#pragma once
#include "GameState.h"
#include "CasillaInventario.h"
#include "ComponenteClickeable.h"
class Inventory :
	public GameState
{
private:
	list <CasillaInventario*> inventario; //deberia ser globaal
	list <CasillaInventario*>::iterator it;
public:
	Inventory();
	virtual ~Inventory();
	Inventory::Inventory(SDLApp* app) : GameState(app) { this->addItem(nullptr, "a", "kk"); this->addItem(nullptr, "a", "Hola"); };
	virtual void update() { for (CasillaInventario* it : inventario) { std::cout << it->getDescription() << endl; } GameState::update(); } //just pruebas de que se añaden bien los objetos y se pueden usar
	void addItem(Texture* txt, string tag, string descripcion);
	//void deleteItem();
};

