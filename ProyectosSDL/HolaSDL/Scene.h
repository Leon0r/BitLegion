#pragma once
#include "GODoors.h"
#include "json.hpp"
#include "ItemInventario.h"
#include "GOTransiciones.h"
#include "ColisionableObject.h"
#include "GOConversational.h"
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
private:
	SDLApp* app;
	int SceneNum;
	list<GameObject*> SceneItems;
	list<GameObject*>::iterator it;
	GameState* CurrentState;
	MainCharacter* pj;
};

