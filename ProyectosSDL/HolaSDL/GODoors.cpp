#include "GODoors.h"
#include "GOTransiciones.h"



GODoors::~GODoors()
{
}

void GODoors::secondAct() {
	app->getStateMachine()->currentState()->getStage()->push_back(new GOTransiciones(app, this->getPosition().getX(), this->getPosition().getY(), this->width_/2, this->height_/2, app->getResources()->getImageTexture(Resources::ImagenTest), scneNum));
}
