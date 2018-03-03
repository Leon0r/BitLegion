#pragma once
#include "ClickeableGO.h"

class GOTransiciones :
	public ClickeableGO
{
public:
	GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture,int _SceneNumber);
	~GOTransiciones();
	void act();
	virtual void saveToJson(json& j) { Vector2D pos = this->getPosition();  json aux; aux["x"] = pos.getX(); aux["y"] = pos.getY();  aux["w"] = this->getWidth(); 
		aux["h"] = this->getHeight(); aux["sceneNumber"] = SceneNumber; j["OTransicion"].push_back(aux);}
private:
	int SceneNumber;
};

