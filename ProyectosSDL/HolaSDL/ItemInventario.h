#pragma once
#include "ClickeableGO.h"
class ItemInventario :
	public ClickeableGO
{
public:
	ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture);
	virtual ~ItemInventario();
	void act();
};

