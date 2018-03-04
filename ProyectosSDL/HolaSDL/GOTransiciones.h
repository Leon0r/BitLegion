#pragma once
#include "ClickeableGO.h"

class GOTransiciones :
	public ClickeableGO
{
public:
	GOTransiciones(SDLApp* game, int x, int y, int w, int h, Texture* texture,int _SceneNumber);
	~GOTransiciones();
	void act();
	virtual void saveToJson(json& j) { json aux = saveBasicsToJson(); aux["sceneNumber"] = SceneNumber; j["OTransicion"].push_back(aux); }
private:
	int SceneNumber;
};

