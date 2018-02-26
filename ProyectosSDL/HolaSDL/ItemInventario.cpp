#include "ItemInventario.h"
#include "MainCharacter.h"
#include "StatePrueba.h" //esto está mal, deberiamos subirlo al padre



ItemInventario::ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture) : ClickeableGO(game,x, y,w,h, texture), desc(_desc), tag(_tag)
{
}


ItemInventario::~ItemInventario()
{
}

void ItemInventario::act() {
	cout << "Hanzo main" << endl;
	StatePrueba* aux = dynamic_cast<StatePrueba*>(app->getStateMachine()->currentState()); //casteo del estado de prueba...

	if (aux != nullptr) {
		MainCharacter* personaje = dynamic_cast<MainCharacter*>(aux->getMainPj()); //casteo del main
		if (personaje != nullptr) {
			personaje->addInventoryObject(this); //añadimos objeto
			app->getStateMachine()->currentState()->deleteElement(this);
		}
	}
}

