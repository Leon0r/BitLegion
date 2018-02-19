#include "ClickeableGO.h"

//Clase de Testeo


ClickeableGO::ClickeableGO(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag ): GameObject()
{
	
	position_ = Vector2D(x, y);
	height_ = h;
	width_ = w;

}


ClickeableGO::~ClickeableGO()
{
}
void ClickeableGO::handleInput(Uint32 time, const SDL_Event& event) {
	if(ComponenteClickeable::handleInput(this, event)) cout << "Pulsado" << endl;
}
