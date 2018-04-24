#pragma once
#include "GameState.h"
#include "Boton.h"
#include "AnimationRenderer.h"


class inGameMenu :
	public GameState
{
public:
	inGameMenu() {};
	~inGameMenu();
	inGameMenu(SDLApp* game);
	vector<Boton*> botones;

private:
	void continueGame(SDLApp* app_);
	static void exitToMenu(SDLApp* app_);
	static void exitGame(SDLApp* app_);
	static void mute(SDLApp* app_) {};

	AnimationRenderer* btext;
	AnimationRenderer* bMenutext;
	AnimationRenderer* bExittext;
	AnimationRenderer* bMutetext;
	function<void()> cGame_;
	function<void()> eGame_;
	function<void()> eMenuGame_;
	function<void()> muteVol_;
};

