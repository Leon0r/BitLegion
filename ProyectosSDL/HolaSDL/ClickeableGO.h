#pragma once
#include "Entity.h"
#include "ComponenteClickeable.h"
#include "ImageRenderer.h"



class ClickeableGO :
	public Entity , ComponenteClickeable
{
public:
	ClickeableGO(SDLApp* game,int x,int y,int w,int h, string _desc, string _tag , Texture* texture);
	virtual ~ClickeableGO();
	void handleInput(Uint32 time, const SDL_Event& event);
	string getTag() { return tag; };
	string getDescription() { return desc; };
	//Texture* getTexture(){ return txt; };
private:
	string desc;
	string tag;
	RenderComponent* render;
	//Texture txt
	bool inRange(int _x) {//prob not final
		return (abs(_x - this->getPosition().getX()) < 150);
	}
	virtual void act() = 0;
	
};

