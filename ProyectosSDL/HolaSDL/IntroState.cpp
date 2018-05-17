#include "IntroState.h"
#include "Entity.h"



IntroState::IntroState()
{
}


IntroState::~IntroState()
{
}

void IntroState::checkAnimDone()
{
	if (done_) app->getStateMachine()->popState();
}

IntroState::IntroState(SDLApp * app) : GameState(app), logo(new Entity(app))
{
	logo->addAnim("Intro", { 0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43 }, false, -1, 100);
	logo->addRenderComponent(new AnimationRenderer(app->getResources()->getImageTexture(Resources::LogosAnim), logo->getAnimations(), 7, 7, 368, 208, this));

	logo->setPosition(Vector2D(0, 0));
	logo->setWidth(368);
	logo->setHeight(208);

	stage.push_back(logo);
}

void IntroState::update()
{
	GameState::update();
	checkAnimDone();
}

void IntroState::receive(Mensaje * msg)
{
	switch (msg->id_) {
	case ANIM_DONE:
		done_ = true;
		break;
		//more cases
	}
}

