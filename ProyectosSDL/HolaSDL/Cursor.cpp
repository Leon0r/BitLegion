#include "Cursor.h"


int Cursor::dependencias = 0;

Cursor::Cursor()
{
}


Cursor::~Cursor()
{
	this->delInputComponent(&fc);
	this->delRenderComponent(&ren);
}

Cursor::Cursor(SDLApp * app, Texture* txt, unsigned int w, unsigned int h): Entity(app)
{
	this->setWidth(w);
	this->setHeight(h); //set de anchura y altura

	fc = FollowCursor();
	this->addInputComponent(&fc); //add del componente que hace que siga al cursor

	ren = ImageRenderer(txt);
	this->addRenderComponent(&ren); //add del render
}
