#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addItem(Texture* txt, string tag, string descripcion) {
	CasillaInventario* newCasilla = new CasillaInventario(app, tag, descripcion); //creamos el objeto con su tag y su descripcion
	SDL_Rect RECT = { 10, 10, 10, 10 };
	//ComponenteClickeable* cmpClick = new ComponenteClickeable(RECT);
	//newCasilla->addInputComponent(cmpClick); No hereda de input ????
	inventario.push_back(newCasilla); //lo guardamos
}
