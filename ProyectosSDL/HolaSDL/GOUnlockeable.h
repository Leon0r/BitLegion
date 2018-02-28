#pragma once
#include "ClickeableGO.h"
class GOUnlockeable :
	public ClickeableGO
{
public:
	GOUnlockeable() {};
	GOUnlockeable(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag) : ClickeableGO(game, x, y, w, h, texture), key(tag) {};
	~GOUnlockeable() {};
private:
	bool opened = false;
	string key;
	virtual void act();
	virtual void secondAct() = 0;
};

