#pragma once
#include "GOUnlockeable.h"
class GODoors :
	public GOUnlockeable
{
public:
	GODoors(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag, int _scneNum) : GOUnlockeable(game, x, y, w, h, texture, tag),scneNum(_scneNum){}
	~GODoors();
	virtual void saveToJson(json& j) {
		Vector2D pos = this->getPosition(); json aux; aux["x"] = pos.getX(); aux["y"] = pos.getY();  aux["w"] = this->getWidth(); aux["h"] = this->getHeight(); 
			aux["tag"] = key; aux["scneNum"] = scneNum; j["GODoors"].push_back(aux); }
private:
	int scneNum;
	void secondAct();
};

