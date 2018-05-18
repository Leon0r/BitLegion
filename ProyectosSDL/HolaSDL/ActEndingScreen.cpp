#include "ActEndingScreen.h"
#include "SDLApp.h"
#include "TransitionScreen.h"

int ActEndingScreen::ACT = 1;

void ActEndingScreen::endState(SDLApp * app_)
{
	app_->getStateMachine()->popState();
	app_->getStateMachine()->pushState(new TransitionScreen(app_, app_->getStateMachine()->currentState(), 600));
}

ActEndingScreen::ActEndingScreen(SDLApp * app, string _header, float time):GameState(app),headers(_header), MaxTime(time)
{
	initTime = SDL_GetTicks();
	title = "Acto: " + to_string(ACT);
	cout << title << endl;
	ACT++;
	fnt = new Font("..//images/Dialogos/Moonace-Regular.ttf", 50);
	fnts = new Font("..//images/Dialogos/Moonace-Regular.ttf", 30);
	fuente = Texture(app->getRenderer(), title, *fnt, col);
}

ActEndingScreen::~ActEndingScreen()
{
	delete fnt;
	delete fnts;
}

void ActEndingScreen::update()
{
	float currentTime = SDL_GetTicks();
	if (initTime + MaxTime < currentTime) {
		endState(app);
	}
}

void ActEndingScreen::render()
{
	fuente.loadFromText(app->getRenderer(), title, *fnt, col);
	fuente.render(app->getRenderer(), app->getWindowWidth() / 2 - fuente.getWidth() / 2, app->getWindowHeight() / 4);

	fuente.loadFromText(app->getRenderer(), headers, *fnts, col);
	fuente.render(app->getRenderer(), app->getWindowWidth()/2 - fuente.getWidth()/2, 2 * app->getWindowHeight() / 5);
}

