#include "OverlapCursorAnimation.h"
#include "Entity.h"



OverlapCursorAnimation::OverlapCursorAnimation()
{
}


OverlapCursorAnimation::~OverlapCursorAnimation()
{
}

void OverlapCursorAnimation::handleInput(GameObject * o, Uint32 time, const SDL_Event & event)
{
	Entity* aux = static_cast<Entity*>(o);
	if (aux->isAnimated()) {
		if (event.type == SDL_MOUSEMOTION) {
			SDL_Point p;
			p.x = event.button.x;
			p.y = event.button.y;

			SDL_Rect rect;
			rect.x = aux->getPosition().getX();
			rect.y = aux->getPosition().getY();
			rect.w = aux->getWidth();
			rect.h = aux->getHeight();

			if (SDL_PointInRect(&p, &rect)) {
				aux->playAnim("Feedback");
			}
			else {
				aux->playAnim("Stop");
			}
		}
	}
}
