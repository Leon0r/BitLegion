#pragma once
#include "GameState.h"
#include "Entity.h"
#include "AnimationRenderer.h"
class ControlesState :
	public GameState
{
private:
	void readFromJson();
	Entity movTeclas;
	Entity movRaton;
	Entity raton;
	Entity fondo;
	Entity teclaPausa;
	Entity teclaInventario;
public:
	ControlesState();
	virtual ~ControlesState();
	ControlesState(SDLApp* app) : GameState(app) { this->readFromJson(); };
	static vector<Entity*> entities;
};

