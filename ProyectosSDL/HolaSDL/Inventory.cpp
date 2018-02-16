#include "Inventory.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) {
	int numElem = 19;
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
	inventario->addItem(txt2, "a", "kk");
	inventario->getItem(0)->setHeight(450);
	inventario->getItem(0)->setWidth(600);
	inventario->getItem(0)->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventario->getItem(0)->getWidth()/2, app->getWindowHeight() / 2 - inventario->getItem(0)->getHeight()/2)));
	for (int i = 1; i <= numElem; i++) {
		inventario->addItem(txt, "b", "kk");
		inventario->getItem(i)->setPosition(Vector2D(matriz[inventario->getLength() - 1] + inventario->getItem(i)->getPosition()));
	}
	inventario->pushObjects(stage);
}