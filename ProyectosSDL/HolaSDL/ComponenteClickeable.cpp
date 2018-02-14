#include "ComponenteClickeable.h"



ComponenteClickeable::ComponenteClickeable(SDL_Rect _rect)
{
	rect = _rect;
}

ComponenteClickeable::~ComponenteClickeable()
{
}

bool ComponenteClickeable::handleEvent(SDL_Event e) {
	
	bool eventHandled = false;

	SDL_Point mouse;
	mouse.x = e.button.x;
	mouse.y = e.button.y;

	if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && SDL_PointInRect(&mouse, &rect)){//Si se pulsa el boton izquierdo del raton y estamos en el rect deseado
			eventHandled = true; 
	}
	return eventHandled;
}