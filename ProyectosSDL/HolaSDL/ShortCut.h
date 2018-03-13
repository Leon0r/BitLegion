#pragma once
#include "Entity.h"
#include "CasillaInventario.h"
#include "Resources.h"
#include "SDLApp.h"
#include "ImageRenderer.h"
#include "ObjectList.h"

//clase shortcut, con 5 huecos para los 5 primeros items del inventario
class ShortCut : public Entity {
private:
	const double coefRed = 1.3;
	vector<Vector2D> matriz;//lugar donde colocaremos los objetos
	const Resources* resources;//imagenes etc.
	CasillaInventario* selected = nullptr;//item seleccionado
	RenderComponent* render;
	RenderComponent* imagenMarca;
	Entity* marca = new Entity(app);//marca del item seleccionado
	bool provisional = false;
	ObjectList* lista;//lista de objetos del inventario
	const int numCas = 5;//numero de casillas (huecos) y relacion de aspecto
	pair<const double, const double> relacion = { app->getWindowWidth() / 800.0, app->getWindowHeight() / 600.0 };
	const double espaciado = (87.0/2.0);
public:
	ShortCut(){};
	ShortCut(SDLApp* game, ObjectList* list, const Resources* resources);
	virtual void handleInput(Uint32 time, const SDL_Event& event);//redefinicion del metodo del padre
	virtual ~ShortCut() {}
	virtual void render(Uint32 time);
	void ini(int pos, double coefred);
	void recorreEInicia(double coefred = 1.0);
	const double getCoef() { return coefRed; }
	void usar();//devuelve el tag del objeto usado
	vector<Vector2D> getMatriz(){ return matriz; }//devuelve la matriz para que el inventario sepa recolocar los objetos cuando se sale de el
};

