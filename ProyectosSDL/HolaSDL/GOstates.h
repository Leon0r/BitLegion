#pragma once
#include "checkML.h"
#include "ClickeableGO.h"

class GOstates :
	public ClickeableGO
{
public:
	GOstates(SDLApp* game, int x, int y, int w, int h, Texture* texture, GameState* state, int rotation = 0);
	virtual ~GOstates();
	void act();
	virtual void saveToJson(json& j) { };
	/*virtual void render(Uint32 time) { 
		Entity::render(time);
	}*/
private:
	GameState* state_;
	int rotation_;
};
