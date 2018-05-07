#pragma once
#include "GOUnlockeable.h"
#include "Observer.h"
#include "ItemInventario.h"
class GOcofres :
	public GOUnlockeable
{
public:
	GOcofres(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag, int wItm, int hItm, string _desc, string _tag, Texture* txtItm, bool permanente = false, char id = NULL) :
		GOUnlockeable(game, x, y, w, h, texture, tag, id), itmW(wItm), itmH(hItm), itmDesc(_desc), itmTag(_tag), itmTexture(txtItm), imtPerm(permanente) {}
	virtual ~GOcofres();

	
	int itmW, itmH;
	string itmDesc, itmTag;
	Texture* itmTexture;
	bool imtPerm;

	void secondAct();

	virtual void saveToJson(json& j) {json aux; Entity::saveToJson(aux); aux["tag"] = key; aux["wItem"] = itmW; aux["hItem"] = itmH; 
	aux["descripcionItem"] = itmDesc; aux["tagItem"] = itmTag; aux["numTextItem"] = app->getResources()->getPosTexture(itmTexture); 
	aux["permanenteItem"] = imtPerm; j["GOCofres"].push_back(aux);};
};

