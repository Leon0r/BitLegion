#pragma once
#include "GameState.h"
class TransitionScreen :
	public GameState
{
public:
	TransitionScreen(SDLApp* game , Uint32 timeLimit = 1500) :GameState(game),MaxTime(timeLimit) { timeStart = SDL_GetTicks(); };
	~TransitionScreen();
	virtual void update();

private:
	Uint32 timeStart, MaxTime;
};

