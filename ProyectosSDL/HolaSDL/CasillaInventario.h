#pragma once
#include "GameComponent.h"
class CasillaInventario :
	public GameComponent
{
private:
	string tag;
	string description;
public:
	virtual ~CasillaInventario();

	//Constructora que recibe el tag y su descripcion
	CasillaInventario(SDLApp* app, string tag, string description) : GameComponent(app), tag(tag), description(description) {};
	string getTag() { return this->tag; };
	string getDescription() { return this->description; };
};

