#pragma once
#include "c:\hlocal\BitLegion\ProyectosSDL\HolaSDL\Entity.h"
#include "c:\hlocal\BitLegion\ProyectosSDL\HolaSDL\GOUnlockeable.h"
class Interruptor :
	public GOUnlockeable
{
private:
	Entity luz_;
	int maxAlpha_;
	int minAlpha_;
	ImageRenderer ausenciaDeLuz;
	bool on_ = false;
	bool canWork_ = false;
public:
	Interruptor();
	~Interruptor();
	Interruptor(SDLApp* app, int x, int y, int w, int h, Texture* txt, string tag, int maxAlpha, int minAlpha, char id = NULL);
	virtual void act();
};

