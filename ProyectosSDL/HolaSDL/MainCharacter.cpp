#include "MainCharacter.h"



MainCharacter::MainCharacter(SDLApp* game,int x, int y, int w, int h, Texture* texture, ObjectList* list): Entity(game), list(list)
{
	//componentes
	render = new ImageRenderer(texture);
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	keyboard = new KeyboardComponent(5, SDLK_RIGHT, SDLK_LEFT, SDLK_UP, SDLK_DOWN, SDLK_i, list);
	this->addInputComponent(keyboard);//componente de input para manejar su direccion
	movement = new MovementComponent();
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
	list->addItem(o); //a�ade un item al inventario
}
