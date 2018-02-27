#include "StatePrueba.h"

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {

	//COLISIONABLES
	Entity* object = new ColisionableObject(app, 500, 500, 100, 100, resources->getImageTexture(Resources::InvMarca));
	stage.push_back(object);
	collision.push_back(object);

	//PERSONAJE
	//Siempre 1� para que ocupe la 1� posicion en la lista
	list = new ObjectList(app);
	alena = new MainCharacter(app, 400, 300, 39, 143, resources->getImageTexture(Resources::Alena), list, collision);
	stage.push_back(alena);

	//SHORTCUT
	shortcut = new ShortCut(app, list, resources);
	stage.push_back(shortcut);

	//ITEMS
	ItemInventario* test = new ItemInventario(app, 368, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test);
	ItemInventario* test2 = new ItemInventario(app, 100, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test2);
	ItemInventario* test3 = new ItemInventario(app, 123, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test3);
	ItemInventario* test4 = new ItemInventario(app, 500, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test4);
	ItemInventario* test5 = new ItemInventario(app, 368, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test5);
	ItemInventario* test6 = new ItemInventario(app, 368, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test6);
	ItemInventario* test7 = new ItemInventario(app, 368, 0, 64, 64, "descripcion", "tag", resources->getImageTexture(Resources::ImagenTest));
	stage.push_back(test7);
}
