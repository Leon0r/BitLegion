#pragma once
#include "ClickeableGO.h"
class GOUnlockeable :
	public ClickeableGO
{
public:
	GOUnlockeable(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag);
	~GOUnlockeable();
private:
	string key;
	void act();
	virtual void secondAct()=0;
};

