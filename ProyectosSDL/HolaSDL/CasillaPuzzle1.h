#pragma once
#include "checkML.h"
#include "Entity.h"
#include "ComponenteClickeable.h"
#include "Texture.h"
#include "ImageRenderer.h"

class CasillaPuzzle1 :
	public Entity
{
private:
	string tag;
	Texture* text;
	RenderComponent* imagen;
	bool special;
public:
	CasillaPuzzle1() {};
	virtual ~CasillaPuzzle1() { 
		text = nullptr;
		delete imagen; imagen = nullptr;
	};
	bool active() { return special; };
	void setActive(bool b) { special = b; }
	//Constructora que recibe el tag y su descripcion
	CasillaPuzzle1(SDLApp* app, string tag, Texture* textura = nullptr,bool _special = false);
	string getTag() { return this->tag; };
	void setTag(string newTag) { this->tag = newTag; };
	virtual void saveToJson(json& j) { json aux;  Entity::saveToJson(aux); aux["tag"] = tag; };
};

