#pragma once
#include "GOUnlockeable.h"
class GODoors :
	public GOUnlockeable
{
public:
	GODoors(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag, int _scneNum) : GOUnlockeable(game, x, y, w, h, texture, tag),scneNum(_scneNum){}
	~GODoors();
	virtual void saveToJson(json& j) { json aux = saveBasicsToJson(); aux["tag"] = key; aux["scneNum"] = scneNum; j["GODoors"].push_back(aux); }
private:
	int scneNum;
	void secondAct();
};

