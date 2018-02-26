#pragma once
#include "GameObject.h"
#include "GameState.h"

class Scene
{
public:
	Scene();
	~Scene();
	Scene(SDLApp* app, int SceneNum) : app(app), SceneNum(SceneNum) {};
	Scene(bool kk, SDLApp* app, int SceneNum);
	void loadScene();
	void exitScene();
	int getSceneNumber() const { return SceneNum; };
private:
	SDLApp* app;
	int SceneNum;
	list<GameObject*> SceneItems;
	list<GameObject*>::iterator it;
	GameState* CurrentState;

};

