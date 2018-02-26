#include "ShortCut.h"


ShortCut::ShortCut(SDLApp* game, ObjectList* list, const Resources* resources)
	:Entity(game), list(list), resources(resources){
	render = new ImageRenderer(resources->getImageTexture(Resources::ShortCut));
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	this->setWidth(resources->getImageTexture(Resources::ShortCut)->getWidth()*relacion.first);
	this->setHeight(resources->getImageTexture(Resources::ShortCut)->getHeight()*relacion.second);
	this->setPosition(Vector2D(app->getWindowWidth() - getWidth(), app->getWindowHeight() - getHeight()));

	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
			matriz[i] = Vector2D(relacion.first*(espaciado*i), relacion.second*(app->getWindowHeight()-this->getHeight()/2));
	}
}

ShortCut::~ShortCut()
{
}
