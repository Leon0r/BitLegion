#pragma once
#include "GameState.h"
#include "Entity.h"
#include "AnimationRenderer.h"
class ControlesState :
	public GameState
{
private:
	void create();
	Entity movTeclas;
	Entity movRaton;
	AnimationRenderer animTeclas;
	AnimationRenderer animRaton;
public:
	ControlesState();
	virtual ~ControlesState();
	ControlesState(SDLApp* app) : GameState(app) {};
};

