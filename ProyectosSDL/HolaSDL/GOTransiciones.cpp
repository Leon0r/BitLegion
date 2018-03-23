#include "GOTransiciones.h"
#include "PlayState.h"
#include "MainCharacter.h"


GOTransiciones::GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture, int _SceneNumber, int rotation):ClickeableGO(game, x, y, w, h,texture), SceneNumber(_SceneNumber), rotation_(rotation)
{
	this->delRenderComponent(render);
	addAnim("RightArrow", { 0,1,2,3});
	addAnim("LeftArrow", { 4,5,6,7 });
	addAnim("DownArrow", { 8,9,10,11 });
	addAnim("UpArrow", { 12,13,14,15 });
	if (render != nullptr) {
		delete render;
		render = nullptr;
	}
	render = new AnimationRenderer(texture,animations,4,4,60,60);
	static_cast<AnimationRenderer*>(render)->playAnim(rotation_);
	this->addRenderComponent(render);
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