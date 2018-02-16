#pragma once
#include "GameObject.h"
#include "ComponenteClickeable.h"
class TestGO :
	public GameObject , ComponenteClickeable
{
public:
	TestGO(SDLApp* game,int x,int y,int w,int h);
	~TestGO();
	void handleInput(Uint32 time, const SDL_Event& event);
	void update(Uint32 time) {};
	void render(Uint32 time) {};
private:
	
};

