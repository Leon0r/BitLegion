#include "MainCharacter.h"


MainCharacter::MainCharacter(SDLApp* game, json& j, ObjectList* list, std::list<GameObject*>* coll, ShortCut* shorcut_, double vel):
	Entity(game), list(list), colisionables(coll), shortCut(shorcut_) {
	// textura
	int n = j["mainPj"]["Texture"];
	_texture = app->getResources()->getImageTexture(Resources::ImageId(n));

	//animaciones
	addAnim("IdleRight", { 20,21,22,23 }, true, -1, 200);//parada a la derecha
	addAnim("IdleLeft", { 16,17,18,19 }, true, -1, 200);//parada a la izquierda
	addAnim("Left", { 0,1,2,3,4,5,6,7 });//caminar a la izquierda 
	addAnim("Right", { 8,9,10,11,12,13,14,15 });//caminar a la derecha

	//componentes
	render = new AnimationRenderer(_texture, animations, 4, 4, 60, 144);
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	movement = new MovementComponent(colisionables);//mueve al jugador cuando se usa el teclado
	keyboard = new KeyboardComponent(vel, SDLK_d, SDLK_a, SDLK_w, SDLK_s, SDLK_i);//decide la direccion del jugador cuando se usa el teclado
	mouseMovement = new MouseMovement(colisionables, vel);
	switcher.addMode({ keyboard, movement, nullptr });//si se pulsa alguna tecla se activaran los componentes de teclado
	switcher.addMode({ mouseMovement, mouseMovement, nullptr });//si se pulsa el raton se activaran los componentes de raton
	switcher.setMode(0);

	//mensajes
	keyboard->addObserver(dynamic_cast<AnimationRenderer*>(render));//teclado a animaciones
	keyboard->addObserver(dynamic_cast<ComponentSwitcher*>(&switcher));//teclado a switcher para no pisarse con mouse
	mouseMovement->addObserver(dynamic_cast<AnimationRenderer*>(render));//mouse a animaciones
	mouseMovement->addObserver(dynamic_cast<ComponentSwitcher*>(&switcher));//mouse a switcher para no pisarse con teclado

	// posicion y dimensiones
	this->setWidth(j["mainPj"]["w"]);//ancho, alto, posicion y textura
	this->setHeight(j["mainPj"]["h"]);
	this->setPosition(Vector2D(j["mainPj"]["x"], j["mainPj"]["y"]));

	// posicion y dimensiones
	this->setWidth(j["mainPj"]["w"]);//ancho, alto, posicion y textura
	this->setHeight(j["mainPj"]["h"]);
	this->setPosition(Vector2D(j["mainPj"]["x"], j["mainPj"]["y"]));

	// items de inventario
	for (int i = 0; i < (int)j["mainPj"]["itemList"].size(); i++) {
		n = j["mainPj"]["itemList"][i]["Texture"];

		
		GameObject* item = new ItemInventario(app, 0, 0, 0, 0,
			j["mainPj"]["itemList"][i]["descripcion"], j["mainPj"]["itemList"][i]["tag"], 
			app->getResources()->getImageTexture(Resources::ImageId(n)));

		addInventoryObject(item);
		delete item;
	}
}

MainCharacter::~MainCharacter()
{
	if (switcher.isKeyBoardComponent()) {
		delete mouseMovement;
		mouseMovement = nullptr;
	}
	else {
		delete movement;
		movement = nullptr;
		delete keyboard;
		keyboard = nullptr;
	}
	_texture = nullptr;
	shortCut = nullptr;
	list = nullptr;
	colisionables = nullptr;
}

void MainCharacter::addInventoryObject(GameObject* o) {
	list->addItem(o); //a�ade un item al inventario
	shortCut->ini(list->getLength()-1, shortCut->getCoef());
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
