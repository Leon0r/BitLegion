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
		inventario->addItem(txt, "b", "kk");
		inventario->getItem(i)->setPosition(Vector2D(matriz[i] + inventario->getItem(i)->getPosition()));
	}
	inventario->deleteItem("b");
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);
}