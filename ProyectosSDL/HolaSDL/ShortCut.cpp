#include "ShortCut.h"


ShortCut::ShortCut(SDLApp* game, ObjectList* list, const Resources* resources) : Entity(game), lista(list), resources(resources){
	render = new ImageRenderer(resources->getImageTexture(Resources::ShortCut));
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	this->setWidth(resources->getImageTexture(Resources::ShortCut)->getWidth()*relacion.first);
	this->setHeight(resources->getImageTexture(Resources::ShortCut)->getHeight()*relacion.second);
	this->setPosition(Vector2D(app->getWindowWidth() - getWidth(), 0));

	imagenMarca = new ImageRenderer(app->getResources()->getImageTexture(Resources::InvMarca));
	marca->addRenderComponent(imagenMarca);
	marca->setHeight(espaciado*relacion.second);
	marca->setWidth(espaciado*relacion.first);

	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
			matriz[i] = Vector2D((espaciado*relacion.first*i)+app->getWindowWidth()-this->getWidth() + espaciado*relacion.first/2,
				(this->getHeight()/2));
	}
}

void ShortCut::handleInput(Uint32 time, const SDL_Event& event) {
	Entity::handleInput(time, event);
	list<CasillaInventario*>::iterator it;
	for (it = lista->getBegin(); it != lista->getEnd(); it++) { //recorre la lista de objetos
		CasillaInventario* aux = (*it);
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event, marca->getWidth(), marca->getHeight())) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				selected = aux;
				marca->setPosition(aux->getPosition() + Vector2D(aux->getWidth() / 2, aux->getHeight() / 2)
					- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear además nuevos objetos para que se muestren por
																				//pantalla (una imagen, la descripción, botones...)
				if (!provisional) {
					provisional = true;
					app->getStateMachine()->currentState()->addEntity(marca);
				}
			}
		}
	}
}

string ShortCut::usar() {
	return selected->getTag();
}

ShortCut::~ShortCut()
{
}
