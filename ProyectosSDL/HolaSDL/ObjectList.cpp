#include "ObjectList.h"



ObjectList::ObjectList()
{
}

void ObjectList::addItem(Texture* txt, string tag, string descripcion) {
	CasillaInventario* newCasilla = new CasillaInventario(app, tag, descripcion); //creamos el objeto con su tag y su descripcion
	ImageRenderer* cmpRender = new ImageRenderer(txt);
	newCasilla->addRenderComponent(cmpRender);
	newCasilla->setWidth(20);
	newCasilla->setHeight(40); //medidas de prueba
	newCasilla->setPosition(Vector2D(-newCasilla->getWidth()/2 , -newCasilla->getHeight()/2));
	objetos.push_back(newCasilla); //lo guardamos
}


void ObjectList::deleteItem(string tag) {
	bool borrado = false;
	it = objetos.begin();
	while (it != objetos.end() && !borrado) {//si no ha llegado al final y no lo ha encontrado
		if ((*it)->getTag() == tag && !borrado) {//si el tag coincide
			borrado = true;
			delete(*it);//lo borra
			it = objetos.erase(it);
		}
		it++;
	}
}

CasillaInventario* ObjectList::getItem(int num) {
	int i = 0;
	bool encontrado = false;
	it = objetos.begin();
	while (it != objetos.end() && !encontrado) {//si no ha llegado al final y no lo ha encontrado
		if (i == num) encontrado = true;//si el num coincide
		else {
			i++;
			it++;
		}
	} return *it; //devuelve el item en el numero num
}
