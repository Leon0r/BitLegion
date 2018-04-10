#include "GOcofres.h"



GOcofres::~GOcofres()
{
}

void GOcofres::secondAct()
{
	list<GameObject*>::iterator it = app->getStateMachine()->currentState()->getStage()->begin();
	it++; it++;
	int x, y;
	x = this->getPosition().getX() + (this->getWidth() / 2) - 30;
	y = this->getPosition().getY() + (this->getHeight() / 2) - 30;
	app->getStateMachine()->currentState()->getStage()->insert
	(it, new ItemInventario(app, x, y, itmW, itmH,itmDesc,itmTag,itmTexture, imtPerm));
}


