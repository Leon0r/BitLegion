#pragma once
#include "GameState.h"
#include "sdl_includes.h"
#include "Font.h"
//#include "Texture.h"

class ActEndingScreen :
	public GameState
{
private:
	float initTime;
	float MaxTime;

	const SDL_Color col = { 0, 169, 0, 1 };
	static int ACT;
	std::string headers;
	Texture fuente;
	std::string title;
	Font* fnt;
	Font* fnts;

	void endState(SDLApp* app_);

public:
	ActEndingScreen(SDLApp* app,string _header = "",float time = 5000);
	~ActEndingScreen();

	virtual void render();
	virtual void update();

};

