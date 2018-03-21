#include "Entity.h"
#include "SDLApp.h"

Entity::Entity(SDLApp* game) :
		GameObject(game), inputComp_(), physicsComp_(), renderComp_() {
}

Entity::~Entity() {
	for (InputComponent* ic : inputComp_) { //problemas al hacer todo esto, hay destructoras perdidas que deben estar mal (o no est�n..)
		if (ic != nullptr) { delete ic; ic = nullptr; }
	}
	for (PhysicsComponent* pc : physicsComp_) {
		if (pc != nullptr) { delete pc; pc = nullptr; }
	}
	for (RenderComponent* rc : renderComp_) {
		if (rc != nullptr) { delete rc; rc = nullptr; }
	}
}

void Entity::handleInput(Uint32 time, const SDL_Event& event) {
	for (InputComponent* ic : inputComp_) {
		ic->handleInput(this, time, event);
	}
}

void Entity::update(Uint32 time) {
	for (PhysicsComponent* pc : physicsComp_) {
		pc->update(this, time);
	}
}

void Entity::render(Uint32 time) {
	for (RenderComponent* rc : renderComp_) {
		rc->render(this, time);
	}
}

void Entity::addInputComponent(InputComponent* ic) {
	inputComp_.push_back(ic);
}

void Entity::addPhysicsComponent(PhysicsComponent* pc) {
	physicsComp_.push_back(pc);
}

void Entity::addRenderComponent(RenderComponent* rc) {
	renderComp_.push_back(rc);
}

void Entity::delInputComponent(InputComponent* ic) {
	std::vector<InputComponent*>::iterator position = std::find(
			inputComp_.begin(), inputComp_.end(), ic);
	if (position != inputComp_.end())
		inputComp_.erase(position);
}

void Entity::delPhysicsComponent(PhysicsComponent* pc) {
	std::vector<PhysicsComponent*>::iterator position = std::find(
			physicsComp_.begin(), physicsComp_.end(), pc);
	if (position != physicsComp_.end())
		physicsComp_.erase(position);
}

void Entity::delRenderComponent(RenderComponent* rc) {
	std::vector<RenderComponent*>::iterator position = std::find(
			renderComp_.begin(), renderComp_.end(), rc);
	if (position != renderComp_.end())
		renderComp_.erase(position);
}

Texture* Entity::getTexture(Uint16 pos) const {
	if (pos < renderComp_.size()) {
		return renderComp_[pos]->getTexture();
	}
}

void Entity::setTexture(Uint16 pos, Texture* newText) {
	if (pos < renderComp_.size()) {
		renderComp_[pos]->setTexture(newText);
	}
}

void Entity::saveToJson(json& j) {
	Vector2D pos = this->getPosition(); j["x"] = pos.getX(); j["y"] = pos.getY();  j["w"] = this->getWidth();
	j["h"] = this->getHeight(); j["Texture"] = app->getResources()->getPosTexture(this->getTexture(0));
}