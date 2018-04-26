#include "pressButtonAnimation.h"
#include "Entity.h"



pressButtonAnimation::pressButtonAnimation()
{
}


pressButtonAnimation::~pressButtonAnimation()
{
}

void pressButtonAnimation::handleInput(GameObject * o, Uint32 time, const SDL_Event & event)
{
	Entity* aux = static_cast<Entity*>(o);
	if (aux->isAnimated()) {
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			SDL_Point p;
			p.x = event.button.x;
			p.y = event.button.y;

			SDL_Rect rect;
			rect.x = aux->getPosition().getX();
			rect.y = aux->getPosition().getY();
			rect.w = aux->getWidth();
			rect.h = aux->getHeight();

			if (SDL_PointInRect(&p, &rect)) {
				aux->playAnim("Pressed");
			}
		}
		else {
			aux->playAnim("Stop");
		}
	}
}
