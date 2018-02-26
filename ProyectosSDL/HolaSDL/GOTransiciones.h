#pragma once
#include "ClickeableGO.h"
class GOTransiciones :
	public ClickeableGO
{
public:
	GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture,int _SceneNumber);
	~GOTransiciones();
	void act();
private:
	int SceneNumber;
};

