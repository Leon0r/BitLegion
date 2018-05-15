#pragma once
#include "GameState.h"
class CreditosState :
	public GameState
{
private:
	Entity* creditos;
	void endCredits();
public:
	CreditosState();
	virtual ~CreditosState();
	CreditosState(SDLApp* app);
	virtual void update();
};

