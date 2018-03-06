#include "ShortCut.h"

ShortCut::ShortCut(SDLApp* game, ObjectList* list, const Resources* resources) : Entity(game), lista(list), resources(resources){
	render = new ImageRenderer(resources->getImageTexture(Resources::ShortCut));
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	//tamaño
	this->setWidth(resources->getImageTexture(Resources::ShortCut)->getWidth()*relacion.first);
	this->setHeight(resources->getImageTexture(Resources::ShortCut)->getHeight()*relacion.second);
	//posicion
	this->setPosition(Vector2D(app->getWindowWidth() - getWidth(), 0));

	//marca de objeto seleccionado
	imagenMarca = new ImageRenderer(app->getResources()->getImageTexture(Resources::InvMarca));
	marca->addRenderComponent(imagenMarca);//componente de pintado para representar un objeto marcado
	marca->setHeight(espaciado*relacion.second);
	marca->setWidth(espaciado*relacion.first);

	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
			matriz[i] = Vector2D((espaciado*relacion.first*i)+app->getWindowWidth()-this->getWidth() + espaciado*relacion.first/2,
				(this->getHeight()/2));
	}
}

//redefinicion del metodo del padre
void ShortCut::handleInput(Uint32 time, const SDL_Event& event) {
	Entity::handleInput(time, event);//llamamos a handleInput del padre
	list<CasillaInventario*>::iterator it;

	for (it = lista->getBegin(); it != lista->getEnd(); it++) { //recorre la lista de objetos
		if ((*it)->pulsacion(event, marca->getWidth(), marca->getHeight())) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
			selected = (*it);//lo marcamos como seleccionado y establecemos la marca en ese lugar
			marca->setPosition((*it)->getPosition() + Vector2D((*it)->getWidth() / 2, (*it)->getHeight() / 2)
				- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it 
													 //y crear además nuevos objetos para que se muestren por pantalla (una imagen, la descripción, botones...)
			if (!provisional) {
				provisional = true;//la primera vez que se ha pulsado un item se añade a la lista marca para que sea pintada (provisional)
				app->getStateMachine()->currentState()->addEntity(marca);
			}
		}
	}
}
