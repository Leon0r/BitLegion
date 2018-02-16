#include "Inventory.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) {
	int numElem = 25;
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(espaciado*j, espaciado*i);
		}
	}
	txt = new Texture();
	txt->loadFromImg(app->getRenderer(), "..//images/Alena.png");
	txt2 = new Texture();
	txt2->loadFromImg(app->getRenderer(), "..//images/Inventario.png");
	imagen = new ImageRenderer(txt2);
	inventarioHud->addRenderComponent(imagen);
	inventarioHud->setHeight(450);
	inventarioHud->setWidth(600);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));

	for (int i = 0; i < numElem; i++) {
		inventario->addItem(txt, "b  " + to_string(i) , "kk");
		inventario->getItem(i)->setPosition(Vector2D(matriz[i] + inventario->getItem(i)->getPosition()));
	}
	inventario->deleteItem("b");
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);
}

void Inventory::handleEvent(SDL_Event& event) {
	for (GameObject* it : stage) { //recorre la lista de objetos
		CasillaInventario* aux = dynamic_cast<CasillaInventario*>(it); //si aux == nullptr --> it no es de tipo CasillaInventario
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event)) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				cout << aux->getDescription() + "  " + aux->getTag();
				cout << "   yey"; // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear además nuevos objetos para que se muestren por
				//pantalla (una imagen, la descripción, botones...)
			}
		}
	}
	GameState::handleEvent(event); //handleEvent del estado, el cual llama al handleInput de todos los GOs de la lista --> componentes normales
}