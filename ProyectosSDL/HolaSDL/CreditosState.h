#pragma once
#include "GameState.h"
class CreditosState :
	public GameState
{
private:
	Entity* creditos;
	void endCredits();
	const int END_DELAY = 50;
public:
	CreditosState();
	virtual ~CreditosState();
	CreditosState(SDLApp* app);
	virtual void update();
};

