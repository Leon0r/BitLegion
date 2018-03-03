#pragma once
#include "GODoors.h"
#include "json.hpp"
#include "ItemInventario.h"
#include "GOTransiciones.h"
#include <fstream>

using json = nlohmann::json;

class Scene
{
public:
	Scene();
	Scene(int numEscena, SDLApp* app);
	~Scene();
	Scene(SDLApp* app, int SceneNum) : app(app), SceneNum(SceneNum) {};
	Scene(bool kk, SDLApp* app, int SceneNum);
	void enterScene();
	void exitScene();
	int getSceneNumber() const { return SceneNum; };
	void saveSceneToJson();
private:
	SDLApp* app;
	int SceneNum;
	list<GameObject*> SceneItems;
	list<GameObject*>::iterator it;
	GameState* CurrentState;


};

