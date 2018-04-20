#include "TransitionScreen.h"



TransitionScreen::~TransitionScreen()
{
}

void TransitionScreen::update()
{
	if ((timeStart + MaxTime) < SDL_GetTicks())
		app->getStateMachine()->popState();
}