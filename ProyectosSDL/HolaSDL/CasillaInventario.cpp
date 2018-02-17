#include "CasillaInventario.h"
#include "ComponenteClickeable.h"

CasillaInventario::~CasillaInventario()
{
	GameComponent::~GameComponent();
}

bool CasillaInventario::pulsacion(const SDL_Event& event){
	ComponenteClickeable cmp;
	bool flag = cmp.handleEvent(this, event); //handle del raton
	return flag;
}
