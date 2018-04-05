#pragma once
#include "GameState.h"
#include "Boton.h"
#include "ImageRenderer.h"


class inGameMenu :
	public GameState
{
public:
	inGameMenu() {};
	~inGameMenu();
	inGameMenu(SDLApp* game);
	vector<Boton*> botones;

private:
	static void continueGame(SDLApp* app_);
	static void exitToMenu(SDLApp* app_);
	static void exitGame(SDLApp* app_);
	static void mute(SDLApp* app_) {};

	RenderComponent* btext;

};

