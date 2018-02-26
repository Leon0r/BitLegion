#pragma once
#include "GameObject.h"
#include "GameState.h"
class Scene
{
public:
	Scene();
	~Scene();
	void loadScene();
	void exitScene();
	//int getSceneNumber();
private:
	int SceneNum;
	list<GameObject*> SceneItems;
	GameState* CurrentState;
};

