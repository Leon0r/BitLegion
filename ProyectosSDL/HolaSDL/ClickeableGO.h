#pragma once
#include "checkML.h"
#include "Entity.h"
#include "ComponenteClickeable.h"
#include "ImageRenderer.h"



class ClickeableGO :
	public Entity , ComponenteClickeable
{
public:
	ClickeableGO() {};
	ClickeableGO(SDLApp* game,int x,int y,int w,int h,  Texture* texture);
	virtual ~ClickeableGO();
	void handleInput(Uint32 time, const SDL_Event& event);
protected:
	
	RenderComponent* render;
	bool inRange(int _x) {//prob not final
		return (abs(_x - this->getPosition().getX()) < 150);
	}
	virtual void act() = 0;
	virtual void saveToJson(json& j) = 0; //se encargarán de guardarse los objetos específicos
	
};

