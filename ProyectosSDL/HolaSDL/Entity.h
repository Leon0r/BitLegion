	#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "GameObject.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include <vector>
#include "Texture.h"

using namespace std;

class Entity : public GameObject {
public:
	Entity() {};
	Entity(SDLApp* game);
	virtual ~Entity();

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	virtual void addInputComponent(InputComponent* ic);
	virtual void addPhysicsComponent(PhysicsComponent* pc);
	virtual void addRenderComponent(RenderComponent* rc);

	virtual void delInputComponent(InputComponent* ic);
	virtual void delPhysicsComponent(PhysicsComponent* pc);
	virtual void delRenderComponent(RenderComponent* rc);
	Texture* getTexture(Uint16 pos) const;
	void setTexture(Uint16 pos, Texture* newText);
	virtual void saveToJson(json& j) {};

private:
	vector<InputComponent*> inputComp_;
	vector<PhysicsComponent*> physicsComp_;
	vector<RenderComponent*> renderComp_;
};

#endif /* GAMECOMPONENT_H_ */