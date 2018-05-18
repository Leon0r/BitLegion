#include "ActEndingScreen.h"
#include "SDLApp.h"




int ActEndingScreen::ACT = 1;



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
	//cout << "exiting Scene" << endl;

	delete fnt;

}

void ActEndingScreen::update()
{
	float currentTime = SDL_GetTicks();
	if (initTime + MaxTime < currentTime) {
		app->getStateMachine()->popState();
	}
}

void ActEndingScreen::render()
{
	fuente.loadFromText(app->getRenderer(), title, *fnt, col);
	fuente.render(app->getRenderer(), app->getWindowWidth() / 2 - fuente.getWidth() / 2, app->getWindowHeight() / 5);

	fuente.loadFromText(app->getRenderer(), headers, *fnts, col);
	fuente.render(app->getRenderer(), app->getWindowWidth()/2 - fuente.getWidth()/2, 2 * app->getWindowHeight() / 5);

}

