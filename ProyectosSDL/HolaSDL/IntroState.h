#pragma once
#include "GameState.h"
#include "AnimationRenderer.h"

class IntroState :
	public GameState
{
private:
	Entity* logo;
public:
	IntroState();
	virtual ~IntroState();
	IntroState(SDLApp* app);
};

