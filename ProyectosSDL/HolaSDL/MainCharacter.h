#pragma once
#include "Entity.h"
#include "ImageRenderer.h"
#include "KeyboardComponent.h"
#include "MovementComponent.h"
#include "ClickeableGO.h"

class MainCharacter:
	public Entity
{
public:
	MainCharacter() {};
	MainCharacter(SDLApp* game, int x, int y, int w, int h, Texture* texture);
	~MainCharacter();
private:
	Texture * _texture;
	RenderComponent* render;
	InputComponent* keyboard;
	PhysicsComponent* movement;

};

