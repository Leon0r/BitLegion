#include "GOTransiciones.h"



GOTransiciones::GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture, int _SceneNumber):ClickeableGO(game, x, y, w, h,texture), SceneNumber(_SceneNumber)
{
}


GOTransiciones::~GOTransiciones()
{
}

void GOTransiciones::act() {

	//Cambio de escena(ScneNumber)
}