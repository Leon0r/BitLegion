#pragma once
#include "Entity.h"
#include "GameState.h"
#include "ComponenteClickeable.h"

class Boton :
	public Entity, ComponenteClickeable
{
private:
	Texture* txt;
	string nombre;
	int f = -1, c = -1;
	typedef void CallBackOnClickApp(SDLApp* app);
	CallBackOnClickApp* inApp; //declaracion del callBack con puntero a la App
	typedef void CallBackOnClickState(GameState* actualState);
	CallBackOnClickState* state; //declaracion del callBack con puntero al state
	typedef void CallBackOnClickStateFC(GameState* actualState, int f, int c);
	CallBackOnClickStateFC* stateFC;
	GameState* actualState;
public:
	Boton() : state(nullptr), inApp(nullptr), actualState(nullptr), Entity(nullptr), nombre("") {}; //constructora vacia
	virtual ~Boton();
	Boton(SDLApp* app, CallBackOnClickApp* inApp, string nombre) : Entity(app), inApp(inApp), nombre(nombre), state(nullptr), actualState(nullptr) {}; //constructora con puntero a la app
	//útil para botones que hacen algo con los estados (start, exit...)
	Boton(SDLApp* app, CallBackOnClickState* state, GameState* actualState, string nombre) : Entity(app), state(state), actualState(actualState), nombre(nombre), inApp(nullptr) {};//constructora
	//con puntero al estado actual, útil para "botones" que hacen cosas en el estado (usar y swap del inventario, maybe objetos interactuables...)
	Boton(SDLApp* app, CallBackOnClickStateFC* stateFC, GameState* actualState, string nombre, int fil, int col) : Entity(app), stateFC(stateFC), actualState(actualState), nombre(nombre), f(fil), c(col) {};//constructora2
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	
};

