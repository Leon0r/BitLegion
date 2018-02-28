#include "GODoors.h"
#include "GOTransiciones.h"



GODoors::~GODoors()
{
}

void GODoors::secondAct() {
	app->getStateMachine()->currentState()->getStage()->push_back(new GOTransiciones(app, this->getPosition().getX(), this->getPosition().getY(), this->width_, this->height_, app->getResources()->getImageTexture(Resources::ImagenTest), scneNum));
}
