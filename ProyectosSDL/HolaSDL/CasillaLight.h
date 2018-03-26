#pragma once
#include "ClickeableGO.h"
class CasillaLight :
	public ComponenteClickeable, public Entity, public Observable
{
private:
	bool encendido;
	pair<const int, const int> pos_;
	ImageRenderer render;
public:
	CasillaLight();
	virtual ~CasillaLight();
	CasillaLight(SDLApp* game, int x, int y, int w, int h, Texture* texture, Observer* obs);
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void act();
	void invertir();
	virtual void saveToJson(json& j) {};
	bool getEncendido() const { return encendido; };

};

