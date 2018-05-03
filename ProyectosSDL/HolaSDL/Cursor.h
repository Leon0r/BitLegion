#pragma once
#include "Entity.h"
#include "FollowCursor.h"
#include "ImageRenderer.h"

class Cursor :
	public Entity
{
private:
	FollowCursor fc;
	ImageRenderer ren;
	static int dependencias;

public:
	Cursor();
	virtual ~Cursor();
	Cursor(SDLApp* app, Texture* txt, unsigned int w, unsigned int h);
	void incrementaDependencias() { dependencias++; };
	int getDependencias() const { return dependencias; };
	void decrementaDependencias() { dependencias--; };
};

