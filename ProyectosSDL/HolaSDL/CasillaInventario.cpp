#include "CasillaInventario.h"


CasillaInventario::~CasillaInventario()
{
	Entity::~Entity();
}

bool CasillaInventario::pulsacion(const SDL_Event& event, int espaciado){
	//Cambio    vvvvvvvvvvvvvvv Antes: This->handleEvent
	SDL_Rect rect;
	rect.x = this->getPosition().getX()+this->getWidth()/2-espaciado/2;
	rect.y = this->getPosition().getY()+this->getHeight()/2-espaciado/2;
	rect.w = espaciado;
	rect.h = espaciado;

	bool flag = ComponenteClickeable::handleInput(&rect, event); //handle del raton
	return flag;
}
