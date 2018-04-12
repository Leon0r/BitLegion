#include "ColisionableObject.h"

ColisionableObject::ColisionableObject(SDLApp* game, int x, int y, int w, int h, Texture* texture) : Entity(game)
{
	//componentes
	render = ImageRenderer(texture);
	this->addRenderComponent(&render);//componente de pintado para que aparezca en pantalla

	this->setWidth(w);//ancho, alto, posicion y textura
	this->setHeight(h);
	this->setPosition(Vector2D(x, y));
}