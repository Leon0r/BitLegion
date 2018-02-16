#include "ComponenteClickeable.h"

ComponenteClickeable::ComponenteClickeable(){}

ComponenteClickeable::~ComponenteClickeable(){}

bool ComponenteClickeable::handleEvent(GameObject* o, const SDL_Event& e) {
	
	bool eventHandled = false;

	SDL_Rect rect;//Inizializacion del Rect
	rect.x = o->getPosition().getX();
	rect.y = o->getPosition().getY();
	rect.w = o->getWidth();
	rect.h = o->getHeight();

	SDL_Point mouse;
	mouse.x = e.button.x;
	mouse.y = e.button.y;

	if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && SDL_PointInRect(&mouse, &rect )){//Si se pulsa el boton izquierdo del raton y estamos en el rect deseado
			eventHandled = true; 
	}
	return eventHandled;
}