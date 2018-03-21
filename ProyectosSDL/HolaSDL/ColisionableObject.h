#pragma once
#include "checkML.h"
#include "Entity.h"
#include "ImageRenderer.h"

class ColisionableObject :
	public Entity
{
public:
	ColisionableObject() {}
	ColisionableObject(SDLApp* game, int x, int y, int w, int h, Texture* texture);
	~ColisionableObject() {}
	virtual void saveToJson(json& j) { json aux; Entity::saveToJson(aux); j["CollisionableObject"].push_back(aux); };
private:
	RenderComponent* render;
};

