#pragma once
#include "ClickeableGO.h"

class GOTransiciones :
	public ClickeableGO
{
public:
	GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture,int _SceneNumber, int rotation = 0);
	~GOTransiciones();
	void act();
	virtual void saveToJson(json& j) { json aux;  Entity::saveToJson(aux); aux["scneNum"] = SceneNumber; aux["rotat"] = rotation_; j["GOTransiciones"].push_back(aux); }
private:
	int SceneNumber;
	int rotation_;
};

