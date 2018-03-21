#pragma once
#include "checkML.h"
#include "ClickeableGO.h"
class GOUnlockeable :
	public ClickeableGO
{
public:
	GOUnlockeable() {};
	GOUnlockeable(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag) : ClickeableGO(game, x, y, w, h, texture), key(tag) {};
	~GOUnlockeable() {};
protected:
	bool opened = false;
	string key;
	virtual void act();
	virtual void secondAct() = 0;
	virtual void saveToJson(json& j) = 0;
};

