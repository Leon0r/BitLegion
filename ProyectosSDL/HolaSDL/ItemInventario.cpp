#include "ItemInventario.h"
#include "MainCharacter.h"
#include "StatePrueba.h" //esto está mal, deberiamos subirlo al padre



ItemInventario::ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture) : ClickeableGO(game,x, y,w,h, _desc,_tag,texture)
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
			int tam = aux->getList()->getLength();
			personaje->addInventoryObject(this); //añadimos objeto
			app->getStateMachine()->currentState()->deleteElement(this);

			if (tam < 5){
				Vector2D mat = aux->getShortCut()->getMatriz()[tam];
				aux->getList()->getItem(tam)->setWidth(aux->getList()->getItem(tam)->getWidth() / coefRed);
				aux->getList()->getItem(tam)->setHeight(aux->getList()->getItem(tam)->getHeight() / coefRed);
				aux->getList()->getItem(tam)->setPosition(Vector2D(mat.getX() - aux->getList()->getItem(tam)->getWidth() / 2,
				mat.getY() - aux->getList()->getItem(tam)->getHeight() / 2));
				aux->addEntity(aux->getList()->getItem(tam));
			}
		}
	}
}

