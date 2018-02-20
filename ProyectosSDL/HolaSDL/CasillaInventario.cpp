#include "CasillaInventario.h"


CasillaInventario::~CasillaInventario()
{
	Entity::~Entity();
}

bool CasillaInventario::pulsacion(const SDL_Event& event){
	//Cambio    vvvvvvvvvvvvvvv Antes: This->handleEvent
	bool flag = ComponenteClickeable::handleInput(this, event); //handle del raton
	return flag;
}
