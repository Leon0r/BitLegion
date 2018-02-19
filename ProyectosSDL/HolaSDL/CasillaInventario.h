#pragma once
#include "GameComponent.h"
#include "ComponenteClickeable.h"

class CasillaInventario :
	public GameComponent, ComponenteClickeable
{
private:
	string tag;
	string description;
public:
	CasillaInventario() {};
	virtual ~CasillaInventario();

	//Constructora que recibe el tag y su descripcion
	CasillaInventario(SDLApp* app, string tag, string description) : GameComponent(app), tag(tag), description(description) {};
	string getTag() { return this->tag; };
	string getDescription() { return this->description; };
	bool pulsacion(const SDL_Event& event);
};

