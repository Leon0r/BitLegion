#include "MainCharacter.h"



MainCharacter::MainCharacter(SDLApp* game,int x, int y, int w, int h, Texture* texture, ObjectList* list, std::list<GameObject*> coll):
	Entity(game), list(list), colisionables(coll)
{
	//componentes
	render = new ImageRenderer(texture);
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	keyboard = new KeyboardComponent(5, SDLK_d, SDLK_a, SDLK_w, SDLK_s, SDLK_i, list);
	this->addInputComponent(keyboard);//componente de input para manejar su direccion
	movement = new MovementComponent(coll);
	this->addPhysicsComponent(movement);//componente de movimiento para que pueda moverse

	this->setWidth(w);//ancho, alto, posicion y textura
	this->setHeight(h);
	this->setPosition(Vector2D(x, y));
	//_texture = texture;
	//_texture

}

MainCharacter::MainCharacter(SDLApp* game, json& j, ObjectList* list, std::list<GameObject*> coll):
	Entity(game), list(list), colisionables(coll) {
	// textura
	int n = j["mainPj"]["Texture"];
	_texture = app->getResources()->getImageTexture(Resources::ImageId(n));

	//componentes
	render = new ImageRenderer(_texture);
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	keyboard = new KeyboardComponent(5, SDLK_d, SDLK_a, SDLK_w, SDLK_s, SDLK_i, list);
	this->addInputComponent(keyboard);//componente de input para manejar su direccion
	movement = new MovementComponent(coll);
	this->addPhysicsComponent(movement);//componente de movimiento para que pueda moverse

	// posicion y dimensiones
	this->setWidth(j["mainPj"]["w"]);//ancho, alto, posicion y textura
	this->setHeight(j["mainPj"]["h"]);
	this->setPosition(Vector2D(j["mainPj"]["x"], j["mainPj"]["y"]));

	// items de inventario
	for (int i = 0; i < j["mainPj"]["itemList"].size(); i++) {
		n = j["mainPj"]["itemList"][i]["Texture"];

		
		GameObject* item = new ItemInventario(app, j["mainPj"]["itemList"][i]["x"], j["mainPj"]["itemList"][i]["y"],
			j["mainPj"]["itemList"][i]["w"], j["mainPj"]["itemList"][i]["h"],
			j["mainPj"]["itemList"][i]["descripcion"], j["mainPj"]["itemList"][i]["tag"], app->getResources()->getImageTexture(Resources::ImageId(n)));
		list->addItem(item);
	}
}

MainCharacter::~MainCharacter()
{
}

void MainCharacter::addInventoryObject(GameObject* o) {
	list->addItem(o); //añade un item al inventario
}

void MainCharacter::changeRoom() {
	if((app->getWindowWidth() - this->position_.getX()) < app->getWindowWidth()/2)
		this->setPosition(Vector2D(10.0, this->position_.getY()));
	else
	{
		this->setPosition(Vector2D(app->getWindowWidth()-(10+ this->width_), this->position_.getY()));
	}
}
