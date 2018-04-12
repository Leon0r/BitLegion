#pragma once
#include "checkML.h"
#include "ClickeableGO.h"

class GOstates :
	public ClickeableGO
{
public:
	GOstates(SDLApp* game, int x, int y, int w, int h, Texture* texture, GameState* state, json j);
	virtual ~GOstates();
	void act();
	virtual void saveToJson(json& j);
private:
	GameState* state_;
	json jAux_; //saber los datos para guardarlos luego. Guardamos el objeto json que tiene tooodo dentro. Facilita maaazo las cosas
};
