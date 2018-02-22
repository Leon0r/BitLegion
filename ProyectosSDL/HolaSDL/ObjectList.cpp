#include "ObjectList.h"
#include "ItemInventario.h"


ObjectList::ObjectList()
{
}

void ObjectList::addItem(GameObject* o) {
	ItemInventario* aux = dynamic_cast<ItemInventario*>(o); //casteo para saber si lo que clickas es o no algo que se pueda a�adir
	if (aux != nullptr) { //si se puede
		if (objetos.size() < 25) {
			CasillaInventario* newCasilla = new CasillaInventario(app, aux->getTag(), aux->getDescription()); //creamos el objeto con su tag y su descripcion
			ImageRenderer* cmpRender = new ImageRenderer(aux->getTexture(0));
			newCasilla->addRenderComponent(cmpRender);
			newCasilla->setWidth(20);
			newCasilla->setHeight(40); //medidas de prueba
			newCasilla->setPosition(Vector2D(-newCasilla->getWidth() / 2, -newCasilla->getHeight() / 2));
			objetos.push_back(newCasilla); //lo guardamos
		}
	}
	else { //si no
		cout << "No es un objeto que se pueda a�adir loko";
	}
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

void ObjectList::swap(CasillaInventario* uno, CasillaInventario* dos){
	//std::swap(*uno, *dos);
	string auxDescription = uno->getDescription(); //guardamos en variables auxiliares la descripcion, tag y textura
	string tagAux = uno->getTag();
	Texture* textAux = uno->getTexture(0);
	uno->setDescription(dos->getDescription()); //set de la descripcion, tag y textura de "uno"
	uno->setTag(dos->getTag());
	uno->setTexture(0, dos->getTexture(0));
	dos->setDescription(auxDescription); //usamos las variables auxiliares para hacer el set de "dos"
	dos->setTag(tagAux);
	dos->setTexture(0, textAux);
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
