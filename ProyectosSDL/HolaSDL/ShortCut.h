#pragma once
#include "Entity.h"
#include "CasillaInventario.h"
#include "Resources.h"
#include "SDLApp.h"
#include "ImageRenderer.h"
#include "ObjectList.h"

class ShortCut : public Entity {
private:
	vector<Vector2D> matriz;
	const Resources* resources;
	RenderComponent* render;
	ObjectList* list;
	const int numCas = 5;
	const double espaciado = 87/2;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0, app->getWindowHeight() / 600.0 };
public:
	ShortCut(){};
	ShortCut(SDLApp* game, ObjectList* list, const Resources* resources);
	virtual ~ShortCut();
};

