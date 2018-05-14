#include "GOcofres.h"



GOcofres::GOcofres(SDLApp * game, int x, int y, int w, int h, Texture * texture, string _tag, char id, GOstates * puzzle):GOUnlockeable(game, x, y, w, h, texture, _tag, id), puzzle(puzzle)
{
	if (puzzle != nullptr)
		puzzle->setActive(false);//Lo desactivamos
	guardado = true;
}

GOcofres::~GOcofres()
{
}

void GOcofres::secondAct()
{
	if (puzzle !=nullptr) {
		puzzle->setActive(true);//Activamos el item
	}
	else {
		this->playAnim("Anim1");

		list<GameObject*>::iterator it = app->getStateMachine()->currentState()->getStage()->begin();
		it++; it++;
		/*int x, y;
		x = this->getPosition().getX() + (this->getWidth() / 2) - 10;
		y = this->getPosition().getY() + (this->getHeight() / 2);*/
		app->getStateMachine()->currentState()->getStage()->insert
		(it, new ItemInventario(app, xItem, yItem, itmW, itmH, itmDesc, itmTag, itmTexture, imtPerm));

		app->getStateMachine()->currentState()->changeList();

		opened = true;
	}
}


