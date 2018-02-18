#pragma once
#include "GameComponent.h"
#include "GameState.h"
class Boton :
	public GameComponent
{
private:
	Texture* txt;
	typedef void CallBackOnClickApp(SDLApp* app);
	CallBackOnClickApp* inApp; //declaracion del callBack con puntero a la App
	typedef void CallBackOnClickState(GameState* actualState);
	CallBackOnClickState* state; //declaracion del callBack con puntero al state
	GameState* actualState;
public:
	Boton() : state(nullptr), inApp(nullptr), actualState(nullptr), GameComponent(nullptr) {}; //constructora vacia
	virtual ~Boton();
	Boton(SDLApp* app, CallBackOnClickApp* inApp) : GameComponent(app), inApp(inApp), state(nullptr), actualState(nullptr) {}; //constructora con puntero a la app
	//útil para botones que hacen algo con los estados (start, exit...)
	Boton(SDLApp* app, CallBackOnClickState* state, GameState* actualState) : GameComponent(app), state(state), actualState(actualState), inApp(nullptr) {};//constructora
	//con puntero al estado actual, útil para "botones" que hacen cosas en el estado (usar y swap del inventario, maybe objetos interactuables...)
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	
};

