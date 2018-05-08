#pragma once
#include "GameState.h"
#include "Boton.h"
#include "AnimationRenderer.h"
#include "MouseEventAnimComponent.h"

class inGameMenu :
	public GameState
{
public:
	inGameMenu() {};
	~inGameMenu();
	inGameMenu(SDLApp* game, GameState* previousState = nullptr);
	vector<Boton*> botones;
	void render();

private:
	void continueGame(SDLApp* app_);
	void exitToMenu(SDLApp* app_);
	void exitGame(SDLApp* app_);
	void mute(SDLApp* app_) { cout << "muteaaaandooooo" << endl; };

	GameState * prevState;
	Texture* txt;

	AnimationRenderer* btext;
	AnimationRenderer* bMenutext;
	AnimationRenderer* bExittext;
	AnimationRenderer* bMutetext;
	MouseEventAnimComponent ov;

	//Cambiar por clase por boton
	function<void()> cGame_;
	function<void()> eGame_;
	function<void()> eMenuGame_;
	function<void()> muteVol_;

	int prevAlpha;
};

