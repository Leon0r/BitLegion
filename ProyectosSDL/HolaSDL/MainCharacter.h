#pragma once
#include "Entity.h"
#include "ImageRenderer.h"
#include "AnimationRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "ItemInventario.h" // Para cargar 
#include "ShortCut.h"

class MainCharacter:
	public Entity
{
public:
	MainCharacter() {};
	MainCharacter(SDLApp* game, json& j, ObjectList* list, std::list<GameObject*>* coll, ShortCut* shortcut_, double vel);
	~MainCharacter();
	void addInventoryObject(GameObject* o);
	void changeRoom();
	string getCurrentTag() { return this->currentTag; };
	ShortCut* getShortcut() { return shortCut; }
	void setCurrenTag(string newTag) { this->currentTag = newTag; };
	ObjectList* getList() { return list; };
	virtual void saveToJson(json& j);
	void clearCollisions() { colisionables->clear(); };
	void setNewCollision(GameObject* o) { colisionables->push_back(o); }

private:
	Texture * _texture;
	ShortCut * shortCut;
	string currentTag;
	RenderComponent* render;
	InputComponent* keyboard;
	PhysicsComponent* movement;
	ObjectList* list;
	std::list<GameObject*>* colisionables;
};

