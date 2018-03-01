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
	CasillaInventario* selected = nullptr;
	RenderComponent* render;
	RenderComponent* imagenMarca;
	Entity* marca = new Entity(app);
	ObjectList* lista;
	const int numCas = 5;
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0, app->getWindowHeight() / 600.0 };
	const double espaciado = (87/2)*relacion.first;
public:
	ShortCut(){};
	ShortCut(SDLApp* game, ObjectList* list, const Resources* resources);
	void handleInput(Uint32 time, const SDL_Event& event);
	virtual ~ShortCut();
	string usar();
	vector<Vector2D> getMatriz(){ return matriz; }
};

