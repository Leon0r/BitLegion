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


MainCharacter::~MainCharacter()
{
}

void MainCharacter::addInventoryObject(GameObject* o) {
	list->addItem(o); //añade un item al inventario
}
