#include "MainMenuState.h"
#include "TransitionScreen.h"
#include "ControlesState.h"


MainMenuState::MainMenuState()
{
}
MainMenuState::MainMenuState(SDLApp * game):GameState(game)
{
	nGame_ = [game]() { // funcion newGame();
		PlayState* playState_ = new PlayState(game); //acceder al estado PlayState

		game->getStateMachine()->pushState(playState_);//pop antes??

		playState_->getScenes()[0]->enterScene();

		//game->getStateMachine()->pushState(new TransitionScreen(game, game->getStateMachine()->currentState(), 3500));
	};

	lGame_ = [game]() { //funcion LoadGame();
		PlayState* playState_ = new PlayState(game, true); //acceder al estado PlayState

		game->getStateMachine()->pushState(playState_);//pop antes??

		playState_->getScenes()[playState_->getNumCurrentScene()]->enterScene(); //entra en la actual

		//game->getStateMachine()->pushState(new TransitionScreen(game, game->getStateMachine()->currentState(), 3500));
	};

	eGame_ = [game]() {
		game->exitGame();//Nunca deberia de haber un estado por encima de este
	};

	controlesFunc_ = [game]() {
		ControlesState* contState = new ControlesState();

		game->getStateMachine()->pushState(contState);

		//game->getStateMachine()->pushState(new TransitionScreen(game, game->getStateMachine()->currentState(), 3500));
	};

	cout << "mainMenu" << endl;
	fondotext = new ImageRenderer(app->getResources()->getImageTexture(Resources::FondoMenu));
	logotext = app->getResources()->getImageTexture(Resources::LogoAnim);

	Boton* b;
	b = new Boton(app, "NewGame", nGame_);
	b->setWidth(150); b->setHeight(100);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, ((app->getWindowHeight() - app->getWindowHeight() / 3) * 1 / 5)+ 250));
	b->addAnim("Feedback", { 16 }, true, -1, 100);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0 }, true, -1, 100);
	btext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonComenzar), b->getAnimations(), 4, 5, 265, 150);
	btext->playAnim("Stop");
	b->setAnimated(true);
	b->addRenderComponent(btext);
	b->addInputComponent(&ov);
	botones.push_back(b); stage.push_back(b);

	b = (new Boton(app, "Load Game", lGame_));
	b->setWidth(150); b->setHeight(100);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, ((app->getWindowHeight() - app->getWindowHeight() / 3) * 2 / 5)+250));
	b->addAnim("Feedback", { 16 }, true, -1, 100);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, true, -1, 100);
	bLoadtext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonLoad), b->getAnimations(), 4, 5, 265, 150);
	bLoadtext->playAnim("Stop");
	b->setAnimated(true);
	b->addRenderComponent(bLoadtext);
	b->addInputComponent(&ov);
	botones.push_back(b); stage.push_back(b);

	b = (new Boton(app, "Exit", eGame_));
	b->setWidth(150); b->setHeight(100);
	b->setPosition(Vector2D(app->getWindowWidth() / 2 - b->getWidth() / 2, ((app->getWindowHeight() - app->getWindowHeight() / 3) * 3 / 5)+250));
	b->addAnim("Feedback", { 16 }, true, -1, 75);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, true, -1, 100);
	bExittext = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonExit), b->getAnimations(), 4, 5, 265, 150);
	bExittext->playAnim("Stop");
	b->addInputComponent(&ov);
	b->addRenderComponent(bExittext);
	b->setAnimated(true);
	botones.push_back(b);stage.push_back(b);

	b = (new Boton(app, "Controles", controlesFunc_));
	b->setWidth(150); b->setHeight(100);
	b->setPosition(Vector2D(100, 400));
	/*b->addAnim("Feedback", { 16 }, true, -1, 75);
	b->addAnim("Stop", { 0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, true, -1, 100);*/
	b->addInputComponent(&ov);
	b->addRenderComponent(new ImageRenderer(app->getResources()->getImageTexture(Resources::BolsaCoca)));
	//b->setAnimated(true);
	botones.push_back(b); stage.push_back(b);

	logo = new Entity(app);
	logo->setPosition({ (double)logo->getGame()->getWindowWidth()/2 - 300, 150 });
	logo->setWidth(600);
	logo->setHeight(203);
	logo->setAnimated(true);
	logo->delEveryRenderComponent();
	logo->addAnim("logoAnim", { 0,0,0,0,0,0,0,0,0,0,0, 1,0,1,0, 3, 3, 3, 5, 0, 0, 0, 4, 4 }, true, -1, 80);
	logo->addRenderComponent(new AnimationRenderer(logotext, logo->getAnimations(), 1, 6, 600, 203));
	stage.push_back(logo);

	fondo = new Entity(app);
	fondo->setPosition({ 0, 0 });
	fondo->setWidth(fondo->getGame()->getWindowWidth());
	fondo->setHeight(fondo->getGame()->getWindowHeight());
	fondo->addRenderComponent(fondotext);
	stage.push_back(fondo);
}

MainMenuState::~MainMenuState()
{
	//stage.clear();
	for (int i = 0; i < botones.size(); i++) { botones.at(i)->delRenderComponent(btext); 
	botones.at(i)->delRenderComponent(bLoadtext); botones.at(i)->delRenderComponent(bExittext); botones.at(i)->delInputComponent(&ov); }
	vector<Boton*>::iterator it;
	for (it = botones.begin(); it != botones.end();it++) {
		this->deleteElement(*it);
	}
	delete(btext);
	delete(bLoadtext);
	delete(bExittext);
}