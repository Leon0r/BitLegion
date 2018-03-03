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
	MainCharacter(SDLApp* game, int x, int y, int w, int h, Texture* texture, ObjectList* list, std::list<GameObject*> coll);
	~MainCharacter();
	void addInventoryObject(GameObject* o);
	void changeRoom();
	string getCurrentTag() { return this->currentTag; };
	void setCurrenTag(string newTag) { this->currentTag = newTag; };
	ObjectList* getList() { return list; };
	virtual void saveToJson(json& j) {};
private:
	Texture * _texture;
	string currentTag;
	RenderComponent* render;
	InputComponent* keyboard;
	PhysicsComponent* movement;
	ObjectList* list;
	std::list<GameObject*> colisionables;
};

