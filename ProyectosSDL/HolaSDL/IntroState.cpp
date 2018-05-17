#include "IntroState.h"
#include "Entity.h"


IntroState::IntroState()
{
}


IntroState::~IntroState()
{
}

IntroState::IntroState(SDLApp * app) : GameState(app), logo(new Entity(app))
{
	logo->addAnim("Intro", {}, false, -1, 100);
	logo->addRenderComponent(new AnimationRenderer(app->getResources()->getImageTexture(Resources::LogoAnim), logo->getAnimations(), 5, 5, 100, 100));

	logo->setPosition(Vector2D(0, 0));
	logo->setHeight(59);
	logo->setWidth(78);

	stage.push_back(logo);
}
