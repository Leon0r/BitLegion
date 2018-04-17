#pragma once
#include "checkML.h"
#include "Entity.h"
#include "GameState.h"
#include "ComponenteClickeable.h"
#include "Messages.h"

class Boton :
	public Entity, public ComponenteClickeable
{
private:
	string nombre;
	int f = -1, c = -1;
	typedef void CallBackOnClickStateFC(GameState* actualState, int f, int c);
	CallBackOnClickStateFC* stateFC;
	GameState* actualState;
	RenderComponent* render_ = nullptr;
	function<void()> fun;
public:
	void setRender(RenderComponent* r) { if (render_ != nullptr) delete render_; render_ = nullptr; render_ = r; }
	Boton() : fun(nullptr), stateFC(nullptr), actualState(nullptr), Entity(nullptr), nombre("") {}; //constructora vacia
	virtual ~Boton();

	Boton(SDLApp* app, CallBackOnClickStateFC* stateFC, GameState* actualState, string nombre, int fil, int col) : Entity(app), stateFC(stateFC), actualState(actualState), nombre(nombre), f(fil), c(col), fun(nullptr) {};//constructora2

	Boton(SDLApp* app, string nombre, function<void()> f) : Entity(app), nombre(nombre), fun(f), stateFC(nullptr) {}; //constructora que recibe cualquier funcion (de tipo void)

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	
};

