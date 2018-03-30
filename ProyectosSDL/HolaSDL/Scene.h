#pragma once
#include "checkML.h"
#include "GODoors.h"
#include "json.hpp"
#include "ItemInventario.h"
#include "GOTransiciones.h"
#include "ColisionableObject.h"
#include <fstream>

using json = nlohmann::json;

class MainCharacter;
class Scene
{
public:
	Scene();
	Scene(int numEscena, SDLApp* app, MainCharacter* pj);
	~Scene();
	//Scene(SDLApp* app, int SceneNum, MainCharacter* pj) : app(app), SceneNum(SceneNum), pj(pj) {};
	void enterScene();
	void exitScene();
	int getSceneNumber() const { return SceneNum; };
	void saveSceneToJson();
	Vector2D getPosIni() { return posIni; }
	void setPosIni(Vector2D newPos) { posIni = newPos; }
private:
	SDLApp* app;
	int SceneNum;
	list<GameObject*> SceneItems;
	list<GameObject*>::iterator it;
	GameState* CurrentState;
	MainCharacter* pj;
	double width = 0, height = 0, x = 0, y = 0;
	Vector2D posIni;
};

