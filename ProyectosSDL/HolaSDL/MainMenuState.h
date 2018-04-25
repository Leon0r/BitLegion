#pragma once
#include "GameState.h"
#include "Boton.h"
#include "PlayState.h"
#include "ImageRenderer.h"
#include "OverlapCursorAnimation.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	MainMenuState(SDLApp* game);
	~MainMenuState();
	vector<Boton*> botones;
private:
	/*static void newGame(SDLApp* app_);
	static void loadGame(SDLApp* app_);
	static void exit(SDLApp* app_);*/
	AnimationRenderer* btext;
	AnimationRenderer* bLoadtext;
	AnimationRenderer* bExittext;
	RenderComponent* fondotext;
	OverlapCursorAnimation ov;
	Texture* logotext;
	Entity* fondo;
	Entity* logo;
	function<void()> nGame_;
	function<void()> lGame_;
	function<void()> eGame_;
};

