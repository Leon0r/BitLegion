#include "Inventory.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) {
	int numElem = 17;
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(espaciado*j + 150, espaciado*i + 125);
		}
	}
	txt = new Texture();
	txt->loadFromImg(app->getRenderer(), "..//images/Alena.png");
	txt2 = new Texture();
	txt2->loadFromImg(app->getRenderer(), "..//images/Inventario.png");
	txt3 = new Texture();
	txt3->loadFromImg(app->getRenderer(), "..//images/InvMarca.png");
	imagen = new ImageRenderer(txt2);
	inventarioHud->addRenderComponent(imagen);
	inventarioHud->setHeight(450);
	inventarioHud->setWidth(600);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));

	imagen = new ImageRenderer(txt3);
	marca->addRenderComponent(imagen);
	marca->setHeight(87);
	marca->setWidth(87);

	for (int i = 0; i < numElem; i++) {
		if(i % 2) inventario->addItem(txt, "b", "kk");
		else inventario->addItem(txt3, "c", "kk2");
		inventario->getItem(i)->setPosition(Vector2D(matriz[i] + inventario->getItem(i)->getPosition()));
	}
	//inventario->deleteItem("b0");
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);
	if (inventario->getLength() != 0) {
		stage.push_back(marca);
		marca->setPosition(inventario->getItem(0)->getPosition() +
			Vector2D(inventario->getItem(0)->getWidth() / 2, inventario->getItem(0)->getHeight() / 2)
			- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2));
		muestraDescripcion(inventario->getItem(0));
	}
}

void Inventory::handleEvent(SDL_Event& event) {
	for (GameObject* it : stage) { //recorre la lista de objetos
		CasillaInventario* aux = dynamic_cast<CasillaInventario*>(it); //si aux == nullptr --> it no es de tipo CasillaInventario
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event)) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				marca->setPosition(aux->getPosition() + Vector2D(aux->getWidth() / 2, aux->getHeight() / 2)
					- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear adem�s nuevos objetos para que se muestren por
				//pantalla (una imagen, la descripci�n, botones...)
				muestraDescripcion(aux);
			}
		}
	}
	GameState::handleEvent(event); //handleEvent del estado, el cual llama al handleInput de todos los GOs de la lista --> componentes normales
}

void Inventory::muestraDescripcion(CasillaInventario* aux) {
	*copia = *aux;
	copia->setHeight(copia->getHeight()*2);
	copia->setWidth(copia->getWidth()*2);
	copia->setPosition(Vector2D(618 - copia->getWidth()/2, 149 - copia->getHeight()/2));
	stage.push_back(copia);
}