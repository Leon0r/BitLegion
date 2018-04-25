#include "inGameMenu.h"



inGameMenu::inGameMenu(SDLApp* game): GameState(game)
{
	cGame_ = [this]() mutable { continueGame(app); };
	cout << "inGameMenu" << endl;

	Boton* b;
	b = (new Boton(app, "Continue", cGame_));
	b->setWidth(150); b->setHeight(90);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 3) * 1 / 3));
	b->addAnim("Feedback", { 16 }, true, -1, 100);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, true, -1, 100);
	btext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonLoad), b->getAnimations(), 4, 5, 265, 150);
	btext->playAnim("Stop");
	b->setAnimated(true);
	b->addInputComponent(&ov);
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	eMenuGame_ = [this]() mutable { exitToMenu(app); };
	b = (new Boton(app, "Exit to Menu", eMenuGame_));
	b->setWidth(150); b->setHeight(90);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 3) * 2 / 3));
	b->addAnim("Feedback", { 16 }, true, -1, 100);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, true, -1, 100);
	bMenutext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonMenu), b->getAnimations(), 4, 5, 265, 150);
	bMenutext->playAnim("Stop");
	b->setAnimated(true);
	b->addInputComponent(&ov);
	b->addRenderComponent(bMenutext);
	botones.push_back(b); stage.push_back(b);

	eGame_ = [this]() mutable {exitGame(app); };
	b = (new Boton(app, "Exit Game", eGame_));
	b->setWidth(150); b->setHeight(90);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 3) * 3 / 3));
	b->addAnim("Feedback", { 16 }, true, -1, 100);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, true, -1, 100);
	bExittext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonExit), b->getAnimations(), 4, 5, 265, 150);
	bExittext->playAnim("Stop");
	b->setAnimated(true);
	b->addInputComponent(&ov);
	b->addRenderComponent(bExittext);
	botones.push_back(b); stage.push_back(b);

	muteVol_ = [this]() mutable {mute(app); };
	b = (new Boton(app, "mute", muteVol_));
	b->setWidth(75); b->setHeight(28);
	b->setPosition(Vector2D(app->getWindowWidth() * (1/7) - 10, app->getWindowHeight() * (1 / 7)+ 10));
	b->addAnim("Feedback", { 0 }, true, -1, 150);
	b->addAnim("Stop", { 1 }, true, -1, 100);
	bMutetext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonMute), b->getAnimations(), 1, 2, 352, 131);
	b->addRenderComponent(bMutetext);
	botones.push_back(b); stage.push_back(b);
}


inGameMenu::~inGameMenu()
{
	for (int i = 0; i < botones.size(); i++) { botones.at(i)->delRenderComponent(btext); botones.at(i)->delRenderComponent(bMenutext); 
	botones.at(i)->delRenderComponent(bExittext);  botones.at(i)->delRenderComponent(bMutetext); botones.at(i)->delInputComponent(&ov); }
	vector<Boton*>::iterator it;
	for (it = botones.begin(); it != botones.end(); it++) {
		this->deleteElement(*it);
	}
	delete(btext);
	delete(bMenutext);
	delete(bExittext);
	delete(bMutetext);
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

