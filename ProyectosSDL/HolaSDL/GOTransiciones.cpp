#include "GOTransiciones.h"
#include "PlayState.h"
#include "MainCharacter.h"


GOTransiciones::GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture, int _SceneNumber):ClickeableGO(game, x, y, w, h,texture), SceneNumber(_SceneNumber)
{
}


GOTransiciones::~GOTransiciones()
{
}

void GOTransiciones::act() {

	//Cambio de escena(ScneNumber)
	//dynamic_cast<PlayState*>(app->getStateMachine()->currentState())->swapScene(SceneNumber);
	PlayState* aux = dynamic_cast<PlayState*>(app->getStateMachine()->currentState());
	if (aux != nullptr) {
		dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->changeRoom();
		aux->swapScene(SceneNumber);
	}
}