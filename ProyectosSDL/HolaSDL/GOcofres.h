#pragma once
#include "GOUnlockeable.h"
#include "Observer.h"
#include "ItemInventario.h"
class GOcofres :
	public GOUnlockeable
{
public:
	GOcofres(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag, int wItm, int hItm, string _desc, string _tag, Texture* txtItm, bool permanente = false, char id = NULL) :
		GOUnlockeable(game, x, y, w, h, texture, tag, id), itmW(wItm), itmH(hItm), itmDesc(_desc), itmTag(_tag),imtPerm(permanente) {}
	virtual ~GOcofres();

	
	int itmW, itmH;
	string itmDesc, itmTag;
	Texture* itmTexture;
	bool imtPerm;

	void secondAct();
};

