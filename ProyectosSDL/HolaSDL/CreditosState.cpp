#include "CreditosState.h"
#include "Entity.h"
#include "ImageRenderer.h"
#include "VerticalMovement.h"
#include "TransitionScreen.h"

void CreditosState::endCredits()
{
	if (creditos->getPosition().getY() + creditos->getHeight() * 1.5 < 0) {
		app->getStateMachine()->popState(false);
		app->getStateMachine()->pushState(new TransitionScreen(app, app->getStateMachine()->currentState(), 1500));
		delete this;
	}
}

CreditosState::CreditosState()
{
}

CreditosState::~CreditosState()
{
	delete creditos;
	stage.clear();
}

CreditosState::CreditosState(SDLApp * app) : GameState(app) {
	creditos = new Entity(app);

	creditos->setHeight(100);
	creditos->setWidth(100);
	creditos->setPosition(Vector2D(app->getWindowWidth()/2 - creditos->getWidth()/2, app->getWindowHeight()));

	creditos->addRenderComponent(new ImageRenderer(app->getResources()->getImageTexture(Resources::AlenaExpresiones)));
	creditos->addPhysicsComponent(new VerticalMovement());

	stage.push_back(creditos);
}

void CreditosState::update()
{
	GameState::update();

	endCredits();
}

