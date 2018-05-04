#pragma once
#include "GameState.h"
#include "Entity.h"
#include "AnimationRenderer.h"
#include "Boton.h"

class ControlesState :
	public GameState
{
private:
	void readFromJson();
	Boton* botonSalir;
	function<void()> exitFun_;
public:
	ControlesState();
	virtual ~ControlesState();
	ControlesState(SDLApp* app) : GameState(app) { exitFun_ = [app]() mutable { app->getStateMachine()->popState(); };  this->readFromJson(); };
	static vector<Entity*> entities;
};

