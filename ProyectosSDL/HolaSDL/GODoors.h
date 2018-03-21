#pragma once
#include "checkML.h"
#include "GOUnlockeable.h"
class GODoors :
	public GOUnlockeable
{
public:
	GODoors(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag, int _scneNum, int rotation = 0) : GOUnlockeable(game, x, y, w, h, texture, tag),scneNum(_scneNum), rotation_(rotation){}
	~GODoors();
	virtual void saveToJson(json& j) { json aux; Entity::saveToJson(aux); aux["tag"] = key; aux["scneNum"] = scneNum; aux["rotat"] = rotation_; j["GODoors"].push_back(aux); }
private:
	int scneNum;
	int rotation_;
	void secondAct();
};

