#include "MainCharacter.h"


MainCharacter::MainCharacter(SDLApp* game, json& j, ObjectList* list, std::list<GameObject*>* coll, double vel):
	Entity(game), list(list), colisionables(coll) {
	// textura
	int n = j["mainPj"]["Texture"];
	_texture = app->getResources()->getImageTexture(Resources::ImageId(n));

	//componentes
	rendere = new ImageRenderer(_texture);
	this->addRenderComponent(rendere);//componente de pintado para que aparezca en pantalla
	movement = new MovementComponent(colisionables);//mueve al jugador cuando se usa el teclado
	keyboard = new KeyboardComponent(vel, SDLK_d, SDLK_a, SDLK_w, SDLK_s, SDLK_i);//decide la direccion del jugador cuando se usa el teclado
	mouseMovement = new MouseMovement(colisionables);//mueve al jugador cuando se usa el raton
	mouse = new MouseDirection(vel, mouseMovement);//decide la direccion del jugador cuando se usa el raton

	switcher.addMode({ keyboard, movement, nullptr });//si se pulsa alguna tecla se activaran los componentes de teclado
	switcher.addMode({ mouse, mouseMovement, nullptr });//si se pulsa el raton se activaran los componentes de raton
	switcher.setMode(0);


	// posicion y dimensiones
	this->setWidth(j["mainPj"]["w"]);//ancho, alto, posicion y textura
	this->setHeight(j["mainPj"]["h"]);
	this->setPosition(Vector2D(j["mainPj"]["x"], j["mainPj"]["y"]));
	kk = new Entity(app);
	kk2 = new Entity(app);
	// items de inventario
	for (int i = 0; i < j["mainPj"]["ItemInventario"].size(); i++) {
		n = j["mainPj"]["ItemInventario"][i]["Texture"];

		
		GameObject* item = new ItemInventario(app, 0, 0, 0, 0,
			j["mainPj"]["ItemInventario"][i]["descripcion"], j["mainPj"]["ItemInventario"][i]["tag"], 
			app->getResources()->getImageTexture(Resources::ImageId(n)));

		addInventoryObject(item);
	}
}

MainCharacter::~MainCharacter()
{
}

void MainCharacter::addInventoryObject(GameObject* o) {
	list->addItem(o); //a�ade un item al inventario
}

void MainCharacter::changeRoom() {
	if((app->getWindowWidth() - this->position_.getX()) < app->getWindowWidth()/2)
		this->setPosition(Vector2D(10.0, this->position_.getY()));
	else
	{
		this->setPosition(Vector2D(app->getWindowWidth()-(10+ this->width_), this->position_.getY()));
	}
}

void MainCharacter::saveToJson(json& j) {
	json aux;
	Entity::saveToJson(aux);

	for (int i = 0; i < list->getLength(); i++) {
		list->getItem(i)->saveToJson(aux["itemList"]);
	}

	j["mainPj"].update(aux);
}
