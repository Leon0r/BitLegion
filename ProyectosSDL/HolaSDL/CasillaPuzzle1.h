#pragma once
#include "Entity.h"
#include "ComponenteClickeable.h"

class CasillaPuzzle1 :
	public Entity, ComponenteClickeable
{
private:
	string tag;
public:
	CasillaPuzzle1() {};
	virtual ~CasillaPuzzle1();

	//Constructora que recibe el tag y su descripcion
	CasillaPuzzle1(SDLApp* app, string tag) : Entity(app), tag(tag) {};
	string getTag() { return this->tag; };
	void setTag(string newTag) { this->tag = newTag; };
	bool pulsacion(const SDL_Event& event, int espaciadoX, int espaciadoY);
	virtual void saveToJson(json& j) { json aux;  Entity::saveToJson(aux); aux["tag"] = tag; };
};

