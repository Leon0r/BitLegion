#include "GOstates.h"
#include "PlayState.h"
#include "MainCharacter.h"


GOstates::GOstates(SDLApp* game, int x, int y, int w, int h, Texture* texture, GameState* state,  int rotation) : ClickeableGO(game, x, y, w, h, texture), rotation_(rotation), state_(state)
{
	this->delRenderComponent(render);
	addAnim("RightArrow", { 0,1,2,3 });
	addAnim("LeftArrow", { 4,5,6,7 });
	addAnim("DownArrow", { 8,9,10,11 });
	addAnim("UpArrow", { 12,13,14,15 });
	if (render != nullptr) {
		delete render;
		render = nullptr;
	}
	render = new AnimationRenderer(texture, animations, 4, 4, 60, 60);
	static_cast<AnimationRenderer*>(render)->playAnim(rotation_);
	this->addRenderComponent(render);
}


GOstates::~GOstates()
{
	if (state_ != nullptr) delete state_;
	state_ = nullptr;
}

void GOstates::act() {
	app->getStateMachine()->currentState()->changeList();
	//Cambio de escena(ScneNumber)
	this->getGame()->getStateMachine()->pushState(state_);
}