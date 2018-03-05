#pragma once
#include "ClickeableGO.h"
class ItemInventario :
	public ClickeableGO
{
public:
	ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture);
	virtual ~ItemInventario();
	void act();
	string getTag() { return tag; };
	string getDescription() { return desc; }
	virtual void saveToJson(json& j) { json aux;  Entity::saveToJson(aux); aux["tag"] = getTag(); aux["descripcion"] = getDescription();  j["ItemInventario"].push_back(aux); }
private:
	string desc;
	string tag;
};

