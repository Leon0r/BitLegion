#pragma once
#include "GameState.h"
#include "Boton.h"
#include "PlayState.h"
#include "ImageRenderer.h"
#include "MouseEventAnimComponent.h"

class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	MainMenuState(SDLApp* game);
	~MainMenuState();
	vector<Boton*> botones;
private:
	AnimationRenderer* btext;
	AnimationRenderer* bLoadtext;
	AnimationRenderer* bExittext;
	RenderComponent* fondotext;
	MouseEventAnimComponent ov{ SDL_MOUSEMOTION, "Feedback", "Stop" };
	Texture* logotext;
	Entity* fondo;
	Entity* logo;
	function<void()> nGame_;
	function<void()> lGame_;
	function<void()> eGame_;
	function<void()> controlesFunc_;
};

