#pragma once
#include "Entity.h"
#include "ImageRenderer.h"
#include "AnimationRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "ComponentSwitcher.h"
#include "ItemInventario.h" // Para cargar 
#include "MouseMovement.h"
//

class MainCharacter:
	public Entity
{
public:
	MainCharacter() {};
	MainCharacter(SDLApp* game, json& j, ObjectList* list, std::list<GameObject*>* coll, double vel);
	virtual ~MainCharacter();
	void addInventoryObject(GameObject* o);
	void changeRoom();
	string getCurrentTag() { return this->currentTag; };
	void setCurrenTag(string newTag) { this->currentTag = newTag; };
	ObjectList* getList() { return list; };
	virtual void saveToJson(json& j);
	void clearCollisions() { colisionables->clear(); };
	void setNewCollision(GameObject* o) { colisionables->push_back(o); }
	virtual void handleInput(Uint32 time, const SDL_Event& event) { switcher.handleInput(time, event); Entity::handleInput(time, event); }
	Entity* kk;
	Entity* kk2;
	virtual void render(Uint32 time) { Entity::render(time); kk->render(time); kk2->render(time); }
	void collisionListWasModified() { mouseMovement->generaMatriz(this); } //m�todo auxiliar, es llamado cuando sales de una escena, para generar de nuevo la matriz de colisionables

private:
	Texture * _texture;
	string currentTag;
	RenderComponent* rendere;
	InputComponent* keyboard;
	PhysicsComponent* movement;
	MouseMovement* mouseMovement;
	ObjectList* list;
	std::list<GameObject*>* colisionables;
	ComponentSwitcher switcher = ComponentSwitcher(app, this);
};

