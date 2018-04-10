#include "inGameMenu.h"



inGameMenu::inGameMenu(SDLApp* game): GameState(game)
{
	cGame_ = [this]() mutable { continueGame(app); };
	cout << "inGameMenu" << endl;
	btext = new ImageRenderer(app->getResources()->getImageTexture(Resources::TicketCompra));
	Boton* b;
	b = (new Boton(app, "Continue", cGame_));
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 1 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	eMenuGame_ = [this]() mutable { exitToMenu(app); };
	b = (new Boton(app, "Exit to Menu", eMenuGame_));
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 2 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	eGame_ = [this]() mutable {exitGame(app); };
	b = (new Boton(app, "Exit Game", eGame_));
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 3 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	muteVol_ = [this]() mutable {mute(app); };
	b = (new Boton(app, "mute", muteVol_));
	b->setWidth(75); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() * (1/8), app->getWindowHeight() * (1 / 8)));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);
}


inGameMenu::~inGameMenu()
{
	for (int i = 0; i < botones.size(); i++)botones.at(i)->delRenderComponent(btext);
	vector<Boton*>::iterator it;
	for (it = botones.begin(); it != botones.end(); it++) {
		this->deleteElement(*it);
	}
	delete(btext);
}


void inGameMenu::continueGame(SDLApp * app_)
{
	app_->getStateMachine()->popState();
}

void inGameMenu::exitToMenu(SDLApp * app_)
{
	app_->getStateMachine()->popState();
	app_->getStateMachine()->popState();
}


void inGameMenu::exitGame(SDLApp * app_)
{
	app_->exitGame();
}

