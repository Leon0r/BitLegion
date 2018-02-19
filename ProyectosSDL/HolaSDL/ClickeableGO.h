#pragma once
#include "GameObject.h"
#include "ComponenteClickeable.h"



class ClickeableGO :
	public GameObject , ComponenteClickeable
{
public:
	ClickeableGO(SDLApp* game,int x,int y,int w,int h, string _desc, string _tag );
	~ClickeableGO();
	void handleInput(Uint32 time, const SDL_Event& event);
	void update(Uint32 time) {};
	void render(Uint32 time) {};
	string getTag() { return tag; };
	string getDescription() { return desc; };
	//Texture* getTexture(){ return txt; };
private:
	string desc;
	string tag;
	//Texture txt
	bool inRange(int _x) {//prob not final
		return (abs(_x - this->getPosition().getX()) < 50);
	}
	
};

