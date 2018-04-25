#pragma once
#include "GameState.h"
#include "Boton.h"
#include "AnimationRenderer.h"
#include "OverlapCursorAnimation.h"

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
	void exitToMenu(SDLApp* app_);
	void exitGame(SDLApp* app_);
	void mute(SDLApp* app_) { cout << "muteaaaandooooo" << endl; };

	AnimationRenderer* btext;
	AnimationRenderer* bMenutext;
	AnimationRenderer* bExittext;
	AnimationRenderer* bMutetext;
	OverlapCursorAnimation ov;
	function<void()> cGame_;
	function<void()> eGame_;
	function<void()> eMenuGame_;
	function<void()> muteVol_;
};

