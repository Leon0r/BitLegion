#include "CasillaPuzzle1.h"

CasillaPuzzle1::CasillaPuzzle1(SDLApp* app, string tag, Texture* textura) : Entity(app), tag(tag), text(textura) 
{
	if (textura != nullptr) {
		imagen = new ImageRenderer(textura);
		addRenderComponent(imagen);
		setWidth(40);
		setHeight(40);
		setVelocity(Vector2D(1, 0));
	}
}
