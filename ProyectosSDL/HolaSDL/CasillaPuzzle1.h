#pragma once
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
public:
	CasillaPuzzle1() {};
	virtual ~CasillaPuzzle1() {};

	//Constructora que recibe el tag y su descripcion
	CasillaPuzzle1(SDLApp* app, string tag, Texture* textura = nullptr);
	string getTag() { return this->tag; };
	void setTag(string newTag) { this->tag = newTag; };
	virtual void saveToJson(json& j) { json aux;  Entity::saveToJson(aux); aux["tag"] = tag; };
};

