#pragma once
#include "GameState.h"
#include "Boton.h"
#include "PlayState.h"
#include "ImageRenderer.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	MainMenuState(SDLApp* game);
	~MainMenuState();
	vector<Boton*> botones;
private:
	static void newGame(SDLApp* app_);
	static void loadGame(SDLApp* app_);
	static void exit(SDLApp* app_);
	RenderComponent* btext;
};

