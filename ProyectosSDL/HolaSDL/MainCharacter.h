#pragma once
#include "Entity.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
//

class MainCharacter:
	public Entity
{
public:
	MainCharacter() {};
	MainCharacter(SDLApp* game, int x, int y, int w, int h, Texture* texture, ObjectList* list, std::list<GameObject*> coll, double vel);
	~MainCharacter();
	void addInventoryObject(GameObject* o);
	
private:
	Texture * _texture;
	RenderComponent* render;
	InputComponent* keyboard;
	PhysicsComponent* movement;
	ObjectList* list;
	std::list<GameObject*> colisionables;
};

