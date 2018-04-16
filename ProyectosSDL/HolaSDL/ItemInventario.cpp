#include "ItemInventario.h"
#include "MainCharacter.h"
#include "PlayState.h" //esto est� mal, deberiamos subirlo al padre



ItemInventario::ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture, bool permanente) : 
	ClickeableGO(game,x, y,w,h, texture), desc(_desc), tag(_tag), permanente_(permanente)
{
}


ItemInventario::~ItemInventario()
{
}

void ItemInventario::act() {
	cout << "Hanzo main" << endl;
	PlayState* aux = dynamic_cast<PlayState*>(app->getStateMachine()->currentState()); //casteo del estado de prueba...

	if (aux != nullptr) {
		MainCharacter* personaje = dynamic_cast<MainCharacter*>(aux->getMainPj()); //casteo del main
		if (personaje != nullptr) {
			personaje->addInventoryObject(this); //a�adimos objeto
			this->setActive(false);
			//app->getStateMachine()->currentState()->deleteElement(this);
		}
	}
}

