#include "GODoors.h"
#include "GOTransiciones.h"



GODoors::~GODoors()
{
}

void GODoors::secondAct() {

	list<GameObject*>::iterator it = app->getStateMachine()->currentState()->getStage()->begin();
	it++; it++;
	app->getStateMachine()->currentState()->getStage()->insert
	( it, new GOTransiciones(app, this->getPosition().getX(), this->getPosition().getY(), this->width_ / 2, this->height_ / 2,
		app->getResources()->getImageTexture(Resources::ImagenTest), scneNum));
}
