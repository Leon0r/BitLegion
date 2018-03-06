#pragma once
#include "ClickeableGO.h"
class ItemInventario :
	public ClickeableGO
{
private:
	static const int coefRed = 3;
public:
	ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture);
	static int getCoef(){ return coefRed; }
	virtual ~ItemInventario();
	void act();
};

