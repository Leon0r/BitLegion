#include "ObjectList.h"



ObjectList::ObjectList()
{
}

void ObjectList::addItem(Texture* txt, string tag, string descripcion) {
	CasillaInventario* newCasilla = new CasillaInventario(app, tag, descripcion); //creamos el objeto con su tag y su descripcion
	ImageRenderer* cmpRender = new ImageRenderer(txt);
	newCasilla->addRenderComponent(cmpRender);
	ComponenteClickeable* cmpClick = new ComponenteClickeable(); //agregamos el metodo clickable
	newCasilla->addInputComponent(cmpClick);
	newCasilla->setWidth(20);
	newCasilla->setHeight(40); //medidas de prueba
	newCasilla->setPosition(Vector2D(app->getWindowWidth() / 2 , app->getWindowHeight() / 2));
	objetos.push_back(newCasilla); //lo guardamos
}
