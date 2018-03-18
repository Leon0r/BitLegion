#pragma once
#include "Entity.h"
#include "ImageRenderer.h"
#include "AnimationRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "ItemInventario.h" // Para cargar 
#include "ShortCut.h"
#include "MouseMovement.h"
#include "ComponentSwitcher.h"

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
	virtual void handleInput(Uint32 time, const SDL_Event& event) { switcher.handleInput(time, event); Entity::handleInput(time, event); }
	void clearCollisions() { colisionables->clear(); };
	void setNewCollision(GameObject* o) { colisionables->push_back(o); }
	void collisionListWasModified() { mouseMovement->generaMatriz(this); } //m�todo auxiliar, es llamado cuando sales de una escena, para generar de nuevo la matriz de colisionables
	MouseMovement* getMouseComponent() const { return mouseMovement; }
	void setSceneWidth(double w) { sceneWidth = w; }
	void setSceneHeight(double h) { sceneHeight = h; }
	double getSceneWidth() { return sceneWidth; }
	double getSceneHeight() { return sceneHeight; }
private:
	Texture * _texture;
	ShortCut * shortCut;
	string currentTag;
	RenderComponent* render;
	InputComponent* keyboard;
	PhysicsComponent* movement;
	MouseMovement* mouseMovement;
	ObjectList* list;
	std::list<GameObject*>* colisionables;
	ComponentSwitcher switcher = ComponentSwitcher(app, this);
	double sceneWidth = 0, sceneHeight = 0;
};

