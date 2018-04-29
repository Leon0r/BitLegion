#include "GOTransiciones.h"
#include "PlayState.h"
#include "MainCharacter.h"


GOTransiciones::GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture, int _SceneNumber):ClickeableGO(game, x, y, w, h,texture), SceneNumber(_SceneNumber)
{
	this->delRenderComponent(render);
	addAnim("Arrow", { 0,1,2,3}, true, -1, 200);
	if (render != nullptr) {
		delete render;
		render = nullptr;
	}
	render = new AnimationRenderer(texture,animations,4,4,60,60);
	this->addRenderComponent(render);
}


GOTransiciones::~GOTransiciones()
{
}

void GOTransiciones::act() {

	//Cambio de escena(ScneNumber)
	PlayState* aux = static_cast<PlayState*>(app->getStateMachine()->currentState());

	if (aux != nullptr) {
		aux->swapScene(SceneNumber);
	}

}