#include "MainMenuState.h"



MainMenuState::MainMenuState()
{
}
MainMenuState::MainMenuState(SDLApp * game):GameState(game)
{
	nGame_ = [game]() { // funcion newGame();
		game->getStateMachine()->pushState(new PlayState(game));//pop antes??
		dynamic_cast<PlayState*>(game->getStateMachine()->currentState())->getScenes()[0]->enterScene(); 
	};

	lGame_ = [game]() { //funcion LoadGame();
		game->getStateMachine()->pushState(new PlayState(game, true));//pop antes??

		PlayState* nPlayState_ = dynamic_cast<PlayState*>(game->getStateMachine()->currentState());

		if (nPlayState_ != nullptr) {
			nPlayState_->getScenes()[nPlayState_->getNumCurrentScene()]->enterScene(); //entra en la actual
			}
	};

	eGame_ = [game]() {
		game->exitGame();//Nunca deberia de haber un estado por encima de este
	};

	cout << "mainMenu" << endl;
	btext = new ImageRenderer(app->getResources()->getImageTexture(Resources::TicketCompra));
	Boton* b;
	b = new Boton(app, "NewGame", nGame_);
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 1 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	b = (new Boton(app, "Load Game", lGame_));
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 2 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b); stage.push_back(b);

	b = (new Boton(app, "Exit", eGame_));
	b->setWidth(100); b->setHeight(75);
	b->setPosition(Vector2D(app->getWindowWidth() / 2, (app->getWindowHeight() - app->getWindowHeight() / 5) * 3 / 3));
	b->addRenderComponent(btext);
	botones.push_back(b);stage.push_back(b);
}

MainMenuState::~MainMenuState()
{
	//stage.clear();
	for(int i =0; i < botones.size();i++)botones.at(i)->delRenderComponent(btext);
	vector<Boton*>::iterator it;
	for (it = botones.begin(); it != botones.end();it++) {
		this->deleteElement(*it);
	}
	delete(btext);
}


/*void MainMenuState::newGame(SDLApp* app_)
{
	app_->getStateMachine()->pushState(new PlayState(app_));//pop antes??
	dynamic_cast<PlayState*>(app_->getStateMachine()->currentState())->getScenes()[0]->enterScene();
}


void MainMenuState::loadGame(SDLApp* app_)
{
	app_->getStateMachine()->pushState(new PlayState(app_,true));//pop antes??

	PlayState* nPlayState_ = dynamic_cast<PlayState*>(app_->getStateMachine()->currentState());

	if (nPlayState_ != nullptr) {
		nPlayState_->getScenes()[nPlayState_->getNumCurrentScene()]->enterScene(); //entra en la actual
	}
}

void MainMenuState::exit(SDLApp* app_)
{
	app_->exitGame();//Nunca deberia de haber un estado por encima de este
}*/