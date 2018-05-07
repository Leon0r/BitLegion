#pragma once
#include "checkML.h"
#include "Entity.h"
#include "GameState.h"
#include "ComponenteClickeable.h"
#include "FeedbackCursorInputComponent.h"

class Boton :
	public Entity, ComponenteClickeable
{
private:
	string nombre;
	int f = -1, c = -1;
	typedef void CallBackOnClickStateFC(GameState* actualState, int f, int c);
	CallBackOnClickStateFC* stateFC;
	GameState* actualState;
	function<void()> fun;

	FeedbackCursorInputComponent feed;

public:
	Boton() : fun(nullptr), stateFC(nullptr), actualState(nullptr), Entity(nullptr), nombre("") {}; //constructora vacia
	virtual ~Boton();

	Boton(SDLApp* app, CallBackOnClickStateFC* stateFC, GameState* actualState, string nombre, int fil, int col); //constructora2

	Boton(SDLApp* app, string nombre, function<void()> f);  //constructora que recibe cualquier funcion (de tipo void)

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	
};

