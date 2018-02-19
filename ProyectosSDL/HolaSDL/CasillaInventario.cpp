#include "CasillaInventario.h"


CasillaInventario::~CasillaInventario()
{
	GameComponent::~GameComponent();
}

bool CasillaInventario::pulsacion(const SDL_Event& event){
	bool flag = handleEvent(this, event); //handle del raton
	return flag;
}
